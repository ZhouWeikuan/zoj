Program zju1014;

const
        maxd = 30;

var
        n : Integer;
        i : integer;
        d : array[1..maxd] of integer;
        l : integer;
        s : string;
        f : string;
        q : Char;
        first:Boolean;

Function CheckLV( p : Integer; c : Char ) : Integer;

Begin
        CheckLV := -1;
        case c of
                '+' : CheckLV := 4 * p + 1;
                '*' : CheckLV := 4 * p + 2;
                '^' : CheckLV := 4 * p + 3;
        End;
End;

Procedure WorkIng(dep : integer; s : String );

var
        i : integer;
        min : integer;
        p, u   : integer;
        t      : integer;
        l1, l2 : integer;

Begin
        if dep > l then Begin
                f := s;
                exit;
        End;
        p := 0;
        min := maxint;
        For i := 1 to length(s) do
                if s[i] <> '(' then
                        if s[i] <> ')' then begin
                                u := checkLV(p, s[i]);
                                if (u <> -1) and (u < min) then min := u;
                        End Else
                        Begin
                                u := 4 * p;
                                p := p - 1;
                                if u < min then min := u;
                        End
                else
                Begin
                        p := p + 1;
                        u := 4 * p;
                        if u < min then min := u;
                End;
        if min = 4 then Begin
//                writeln(l1,' ', l2, ' ',copy(s, l1+1, l2-l1-1));
                WorkIng(dep + 1, copy(s, 2, length(s)-2));
                exit;
        End;
        t := d[dep]; l1 := 0; l2 := -1;
        For i := 1 to length(s) do
                if s[i] <> '(' then
                        if s[i] <> ')' then begin
                                u := checkLV(p, s[i]);
                                if u = min then Begin
                                        t := t - 1;
                                        if l2 < 0 then l2 := i else
                                        Begin
                                                l1 := l2;
                                                l2 := i;
                                        End;
                                        if t = 0 then Break;
                                End;
                        End Else
                                p := p - 1
                else
                        p := p + 1;
        if t > 0 then
                if l2 < 0 then l2 := length(s) + 1 else
                Begin
                        l1 := l2;
                        l2 := length(s)+1;
                End;
//        writeln(l1,' ', l2, ' ',copy(s, l1+1, l2-l1-1));
        Working(dep+1, copy(s, l1+1, l2 - l1 - 1));
End;

Begin
        first := true;
        Repeat
                Readln(s);
                if s = '*' then exit;
                if first then
                        first := False else writeln;
                q := s[1];
                writeln('Expression ', s[1], ':');
                s := copy(s, 4, length(s) - 3);
                Readln(n);
                While n > 0 do Begin
                        l := 0;
                        while not eoln do Begin
                                inc(l);
                                read(d[l]);
                        End;
                        Readln;
                        WorkIng(1, s);
                        For i := l downto 1 do
                                write('op(',d[i],',');
                        write(q);
                        for i := 1 to l do write(')');
                        write('=');
                        writeln(f);
                        Dec(n);
                End;
        Until False;
end.

