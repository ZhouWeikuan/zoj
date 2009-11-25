#!/usr/bin/perl
use Data::Dumper;
use GDBM_File;

my %zju;

sub getInput {
	my %h;
	tie (%h,'GDBM_File', 'zju.gdbm', &GDBM_READER, 0660);
	foreach my $k(keys %h){
		@a = split /\s+/,$h{$k},7;
		my $lh = \ {no=>$a[0], ratio=>$a[1], resolve=>$a[2], total=>$a[3], fail=>$a[4], prio=> $a[5] , name=>$a[6]};
		$zju{$k} = $lh;
	}
    untie %h;
}

sub saveInput {
	my %h;
	tie %h, 'GDBM_File', 'zju.gdbm', &GDBM_NEWDB, 0660;
	%h=();
	foreach my $k(keys %zju){
		my $ref = ${$zju{$k}};
		my @a = ($ref->{no}, $ref->{ratio}, $ref->{resolve}, $ref->{total}, $ref->{fail}, $ref->{prio}, $ref->{name});
		$v = join(" ", @a);
		$h{$k} = $v;
	}
    untie %h;
}
sub Main(){	
	while(1){
		my @a = keys %zju;
	($top,@a) = sort { ${$zju{$b}}->{prio} <=> ${$zju{$a}}->{prio}} @a;
		my $ref = ${$zju{$top}};
		print "The current problem ID: [32;47;1m $ref->{no} [m, name: $ref->{name}\n";
        my $r = $ref->{ratio} ;
		print "prio: $ref->{prio}, ratio: $r%, $ref->{resolve}/$ref->{total}\n";
		print "Left problems: ", 1 + (scalar @a),"\n";
		print " A) Accept\n";
		print " B) Wrong answer\n";
		print " C) Ignore \n";
		print " D) Exit\n";
		my $input = <>;
		my $inc;
		$input = substr($input,0,1);
		$input =uc($input);
		if($input eq 'A'){ #ac
			delete $zju{$top};
			next;
		} elsif($input eq 'B'){ #wrong
			$inc = 2;
		} elsif($input eq 'D'){ # exit
			return;
		} else {
			$inc = 1;
		}
		$ref->{fail} += $inc;
		$ref->{prio} = int ($ref->{resolve} - 20 * $ref->{fail});
	}
}

getInput ;
Main();
saveInput;
