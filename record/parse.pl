#!/usr/bin/perl
use GDBM_File;
use Data::Dumper;
use constant {
    LIM => 24,
};

my @a = ();
open (FH,"<zju.sub") or die "can't open file: zju.sub";
while(<FH>){
	my @t = split /\s+/;
	push @a,@t;
}
close(FH);
my %e;
foreach(@a){
	$e{$_} = 1;
}

sub trim {
    my $v = shift;
    $v =~ s/\<.*?\>//g;
    $v =~ s/\s+//g;
    return $v;
}

tie (%h, 'GDBM_File', 'zju.gdbm', &GDBM_WRCREAT, 0660);

#$pat='<tr>.*?(\d+)</td>.*?pid=.*?>(.*?)</a></td>.*?><font color=green>(.*?)%&nbsp;\((\d+)\/(\d+)\).*?</tr>';
$pat='<td class="problemId">(<.*?)</td>\s*<td class\S+>(.*?)</td>\s*<td class\S+>(.*?)</td>';

sub parse {
	my $pre = scalar keys %h;
	my $filename = shift;
	my @a;
	open(FH,"<$filename");
	@a = <FH>;
	close(FH);
	chomp(@a);
	my $file = join(" ",@a);
	while($file =~/$pat/g){
		my $no = trim($1);
		if(exists $e{$no}){
			next;
		}
		my $filename = trim($2);
        my $str = trim($3);
        $str =~/(\S+?)%.*?(\d+)\/(\d+)/;
		my $ratio = $1;
		my $resolve = $2;
		my $total = $3;
		my $fail = 0;
		my $prio = int($resolve);
		$v = "$no $ratio $resolve $total $fail $prio $filename";
#        print "$v\n";
        if(not exists $h{$no}){
		    $h{$no} = $v;
        }
	}
    my $cur = scalar keys %h;
    $cur -= $pre;
    print "added for $filename: $cur\n";
}

#begin sdkf
for($i=1;$i<LIM;$i++){
	parse "$i.html";
}
#end
#print Dumper(\%h);
print scalar keys %h,"\n";
untie %h;

