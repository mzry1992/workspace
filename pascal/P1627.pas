var
        n,l,r,i,j,maxans,temp:longint;
        ll,rr,d,f,c:array[1..1000] of longint;
        ss:array[0..1001] of longint;

function max(a,b:longint):longint;
begin
        if a > b then exit(a);
        exit(b);
end;

begin
        assign(input,'1.txt');
        reset(input);

        readln(n,l,r);
        for i := 1 to n do      read(d[i]);
        readln;
        for i := 1 to n do      read(f[i]);
        readln;
        ss[0] := 0;
        ss[1001] := 0;
        for i := 1 to n do
        begin
                read(c[i]);
                ss[i] := ss[i-1]+c[i];
        end;
        readln;
        fillchar(rr,sizeof(rr),0);
        fillchar(ll,sizeof(ll),0);
        for i := 1 to n do
        begin
                for j := i to n do
                        rr[i] := max(ss[j]-ss[i]-(j-i)*(r+l),rr[i]);
                for j := i downto 1 do
                        ll[i] := max(ss[i-1]-ss[j-1]-(i-j)*(r+l),ll[i]);
        end;

        maxans := -maxlongint;
        for i := 1 to n do
        begin
                for j := i to n do
                begin
                        temp := ss[j]-ss[i-1]-(j-i)*r-d[i]-f[j];
                        maxans := max(temp+rr[j]+ll[i],maxans);
                end;
                for j := i downto 1 do
                begin
                        temp := ss[i]-ss[j-1]-(i-j)*r-d[i]-f[j];
                        maxans := max(temp+ll[j]+rr[i],maxans);
                end;
        end;
        writeln(maxans);

        close(input);
end.

