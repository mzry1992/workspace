var
        tn,fn,final,fk,ft,fj,total,tg:longint;
        time,number:array[0..100000] of longint;
procedure       qsort(l,r:longint);
var
        i,j,m,t:longint;
begin
        i := l; j := r; m := time[(i+j) div 2];
        repeat
                while m > time[i] do    inc(i);
                while m < time[j] do    dec(j);
                if i <= j then
                begin
                        t := time[i];   time[i] := time[j];     time[j] := t;
                        t := number[i]; number[i] := number[j]; number[j] := t;
                        inc(i);
                        dec(j);
                end;
        until i > j ;
        if i < r then   qsort(i,r);
        if j > l then   qsort(l,j);
end;
begin
        time[0] := 0;
        number[0] := 0;
        readln(tn,final);
        time[tn+1] := final;
        number[tn+1] := 0;
        for fn := 1 to tn do    readln(time[fn],number[fn]);
        qsort(0,tn+1);

end.
