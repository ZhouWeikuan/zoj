use integer;

$case = 50 + rand(50);
while($case --){
    $num = 1 + rand(20);
    print "$num\n";
    while($num --){
        $a = 1 + rand(40);
        $b = 1+ $a + rand(40);
        $c = 0 + rand(80);
        print "$a $b $c\n";
    }
}
