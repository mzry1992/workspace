var
        t,tt,n,i,temp:longint;
        a:array[0..9] of boolean;

function getmin:longint;
var
        i,j,t1,t2:longint;
        s1,s2:string;
begin
        s1 := '';
        s2 := '';
        for i := 0 to 9 do
        if a[i] then
        begin
                s1 := s1+chr(i+ord('0'));
                s2 := chr(i+ord('0'))+s2;
        end;
        val(copy(s1,1,length(s1) div 2),t1);
        val(copy(s2,1,length(s2) div 2),t2);
        exit(t1-t2);
end;

procedure done;
var
        i,j,total,ans,min,ex:longint;
begin
        total := 0;
        for i := 0 to 9 do
        if a[i] then inc(total);
        if total = 0 then
        begin
                writeln(0);
                exit;
        end;
        if total = 1 then
        begin
                for i := 0 to 9 do
                if a[i] then
                begin
                        writeln(i);
                        exit;
                end;
        end;
        if total = 2 then
        begin
                j := -1;
                for i := 0 to 9 do
                if a[i] then
                if j = -1 then
                        j := i
                else
                begin
                        j := abs(i - j);
                        writeln(j);
                        exit;
                end;
        end;
        if total mod 2 = 1 then
        begin
                ans := -1;
                for i := 1 to 9 do
                if a[i] then
                if ans = -1 then
                        ans := i;
                a[ans] := false;
                ex := 1;
                for i := 1 to (total-1) div 2  do
                        ex := ex*10;
                ans := ans*ex;
                ans := ans+getmin;
                writeln(ans);
                exit;
        end;
        ex := 1;
        for i := 1 to total div 2 -1 do
                ex := ex*10;
        min := maxlongint;
        for i := 1 to 9 do
        for j := 0 to 9 do
        if i > j then
        if a[i] and a[j] then
        begin
                ans := (i-j)*ex;
                a[i] := false;
                a[j] := false;
                ans := ans+getmin;
                if ans < min then min := ans;
                a[i] := true;
                a[j] := true;
        end;
        writeln(min);
        exit;
end;

begin
        readln(t);
        for tt := 1 to t do
        begin
                readln(n);
                fillchar(a,sizeof(a),false);
                for i := 1 to n do
                begin
                        read(temp);
                        a[temp] := not a[temp];
                end;
                readln;
                done;
        end;
end.

