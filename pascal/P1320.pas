var     c:array[1..500000] of longint;
        k,tk,n,a,b,code,tnow,cnow,j:longint;
        st:string;

procedure done(st:string;var a,b,code:longint);
begin
        if st[1]='A' then
        begin
                st:=copy(st,3,length(st)-2);
                val(st,a);
                code:=1;
                exit;
        end;
        if st[1] in ['B','C'] then
        begin
                if st[1] = 'B' then code:=2 else code:=3;
                st:=copy(st,3,length(st)-2);
                val(copy(st,1,pos(' ',st)-1),a);
                val(copy(st,pos(' ',st)+1,length(st)-pos(' ',st)),b);
                exit;
        end;
end;

begin
        readln(n,k);
        fillchar(c,sizeof(c),0);
        tnow := 0;
        cnow := 0;
        for tk := 1 to k do
        begin
                readln(st);
                done(st,a,b,code);
                case code of
                1       :
                        begin
                                for j := tnow+1 to a do cnow := cnow+c[j];
                                tnow := a;
                                writeln(cnow);
                        end;
                2       :
                        begin
                                if a > tnow then        c[a] := c[a]+b
                                else
                                        cnow := cnow + b;
                        end;
                3       :
                        begin
                                if a > tnow then        c[a] := c[a]-b
                                else
                                        cnow := cnow - b;
                        end;
                end;
        end;
end.
