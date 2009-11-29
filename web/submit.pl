use LWP::UserAgent;
use HTTP::Request::Common;
use HTTP::Response;
use Data::Dumper;
use strict;

my $browser = LWP::UserAgent->new();
$browser->agent("Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9.0.4)Gecko/2008111217"
            ." Fedora/3.0.4-1.fc10 Firefox/3.0.4");

sub readFile($){
    my $filename = shift;
    local $/;
    open (FD, " < $filename") or die "can't open file $filename: $!\n";
    my $text = <FD>;
    close(FD);
    return $text;
}

sub createItem($){
    my $id = shift;
    my $ref = [];
    push @$ref, "ProbID", $id;
    my $file = "../zju.finished/$id.c";
    if (! -f $file){
        $file = "../zju.finished/$id.cpp";
        if (! -f $file){
            return 0;
        }
    }
    my $out = 'output.html';
    `webcpp $file $out -t=4 -s -X 1>&/dev/null`;
    my $text = readFile($out);
    push @$ref, "HtmlSource", $text;
    `rm -f typical.css 1>&/dev/null`;
    `rm -f $out 1>&/dev/null`;
    return $ref;
}

sub sendOneProblem($){
    my $param = shift;
    my $response = $browser->request (POST "http://192.168.1.86/zoj/updateCodes.php",
            $param) ;

    if ($response->is_success) {
        print $response->content;
    } else {
        print STDERR $response->status_line, "\n";
    }

}

my $arg = shift;
if ($arg > 1000 && $arg < 9999){
    my $params = createItem($arg);
    if ($params){
        sendOneProblem($params);
    }
    exit(0);
}
print "Do you want to submit all problems?[N]: ";
my $ans = <>;
if ($ans !~/^[yY]/){
    exit(0);
}

for (my $i=1000; $i<1004; ++$i){
    my $params = createItem($i);
    if ($params){
        sendOneProblem($params);
    }
}

