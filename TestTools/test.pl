`perl ./gen.pl > input.txt`;
`time ./a.out < input.txt > my.out`;
`time ./other < input.txt > other.out`;
@a = `diff my.out other.out`;
print @a;
print "\n"
