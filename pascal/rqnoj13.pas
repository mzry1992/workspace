var
        long,n,i,j,temp,count,nl,nr:longint;
        l,r:array[1..100] of longint;
begin
        readln(long,n);
        for i := 1 to n do      readln(l[i],r[i]);
        for i := 1 to n-1 do
        for j := i+1 to n do
        if l[i] > l[j] then
        begin
                temp := l[i];   l[i] := l[j];   l[j] := temp;
                temp := r[i];   r[i] := r[j];   r[j] := temp;
        end;
        nl := l[1];
        nr := r[1];
        count := 0;
        for i := 2 to n-1 do
        if l[i] <= nr then
                nr := r[i]
        else
        if l[i] > nr then
        begin
                count := count+nr-nl+1;
                nl := l[i];
                nr := r[i];
        end;
        if l[n] <= nr then
        begin
                nr := r[n];
                count := count+nr-nl+1;
        end
        else
        if l[n] > nr then
                count := count+nr-nl+1+r[n]-l[n]+1;
        writeln(long-count+1);
end.
