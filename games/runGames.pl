use HTTP::Request;
use LWP::UserAgent;

sub genMap {
    my @out;
    open(FD, "< index.html");
    while(<FD>){
        if (/FlashVars=\"x=(\d+)\&y=(\d+)\&board=(.*?)\"/){
            push @out, "$1 $2";
            push @out, split(",",$3);
            open(OUT, "> input");
            print OUT join("\n", @out);
            close(OUT);
            last;
        }
    }
    close(FD);
}

my $game = shift;
if ($game eq ''){
    print "Please input the game name!\n";
    exit(-1);
}
`rm -rf $game && make $game` or die "$!\n";

my $wget = 'wget --cookies=on --keep-session-cookies --load-cookies=cookie.txt --save-cookies=cookie.txt ';
my $url = "http://www.hacker.org/$game/index.php";
my $cmd = "$wget $url -O index.html";
system($cmd);
my $pre = "ab";
my $path = "";
my $lvl = 0;
while($pre ne $path){
    print "Level: $lvl\n";
    $pre = $path;
    genMap();
    last if (!-f "input");
    $path = `./$game < input`;
    chomp($path);
    `/bin/echo "\n$path\n" >> input`;
    $cmd = "$wget $url?$path -O index.html";
    print "$cmd\n";
    system($cmd);
    `mv input input.$lvl`;
    ++$lvl;
}

