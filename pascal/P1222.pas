var
        a,b,n,i,j,tans,mans:longint;
        f1,f2:array[-2600..2600] of longint;
        u1,u2:array[-2600..2600] of boolean;
function        min(a,b:longint):longint;
begin
        if a < b then   exit(a);
        exit(b);
end;
begin
        readln(n);
        fillchar(f1,sizeof(f1),0);
        fillchar(u1,sizeof(u1),false);
        u1[0] := true;
        for i := 1 to n do
        begin
                readln(a,b);
                fillchar(u2,sizeof(u2),false);
                fillchar(f2,sizeof(f2),0);
                for j := -2500 to 2500 do
                begin
                        if u1[j+a-b] and u1[j-a+b] then
                        begin
                                f2[j] := min(f1[j+a-b],f1[j-a+b]+1);
                                u2[j] := true;
                        end
                        else
                        if u1[j+a-b] then
                        begin
                                f2[j] := f1[j+a-b];
                                u2[j] := true;
                        end
                        else
                        if u1[j-a+b] then
                        begin
                                f2[j] := f1[j-a+b]+1;
                                u2[j] := true;
                        end;
                end;
                u1 := u2;
                f1 := f2;
        end;
        for i := 0 to 2500 do
        begin
                if u1[i] and u1[-i] then
                begin
                        writeln(min(f1[i],f1[-i]));
                        halt;
                end;
                if u1[i] then
                begin
                        writeln(f1[i]);
                        halt;
                end;
                if u1[-i] then
                begin
                        writeln(f1[-i]);
                        halt;
                end;
        end;
end.
