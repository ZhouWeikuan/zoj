#!/usr/bin/perl
use strict;
use constant {
    LIM => 24,
};

my $pre = 'http://acm.zju.edu.cn/onlinejudge'
        . '/showProblems.do?contestId=1&pageNumber=';
for(my $i=1; $i < LIM ; $i++){
	my $url = $pre . "$i";
	`wget \"$url\" -c -O $i.html`;
}
