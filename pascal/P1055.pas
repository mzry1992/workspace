var
        l,w,n,i,j:longint;
        x,y:array[1..5004] of longint;
        bs,bx,bl,br:longint;
        max,temp,mj:longint;

procedure qsort(l,r:longint);
var
        i,j,m,temp:longint;
begin
        i := l; j := r; m :=x[(i+j) div 2];
        repeat
                while x[i] < m do       inc(i);
                while x[j] > m do       dec(j);
                if i <= j then
                begin
                        temp := x[i];   x[i] := x[j];   x[j] := temp;
                        temp := y[i];   y[i] := y[j];   y[j] := temp;
                        inc(i); dec(j);
                end;
        until i > j;
        if i < r then qsort(i,r);
        if j > l then qsort(l,j);
end;

begin
        readln(l,w);
        readln(n);
        for i := 1 to n do      readln(x[i],y[i]);
        x[n+1] := 0;    y[n+1] := 0;
        x[n+2] := 0;    y[n+2] := w;
        x[n+3] := l;    y[n+3] := 0;
        x[n+4] := l;    y[n+4] := w;
        n := n+4;
        qsort(1,n);
        max := 0;
        for i := 1 to n do
        begin
                bl := x[i];
                bs := w;
                bx := 0;
                temp := 0;
                for j := i+1 to n do
                begin
                        br := x[j];
                        mj := (br-bl)*(bs-bx);
                        writeln(bl,' ',br,' ',bs,' ',bx,' ',mj,' ',x[i],' ',y[i],' ',x[j],' ',y[j]);
                        if mj > temp then temp := mj;
                        if y[j] > y[i] then
                        begin
                                if y[j] < bs then
                                        bs := y[j];
                        end
                        else
                                if y[j] > bx then
                                        bx := y[j];
                end;
                if temp > max then max := temp;
        end;
        writeln(max);
end.