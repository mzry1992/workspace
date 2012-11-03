const
        ly:array[1..12] of longint = (31,29,31,30,31,30,31,31,30,31,30,31);
        py:array[1..12] of longint = (31,28,31,30,31,30,31,31,30,31,30,31);
var
        time:string;
        t0,t1,t2:array[1..6] of longint;
        i,j:longint;
begin
        t0[1] := 1990;
        t0[2] := 5;
        t0[3] := 18;
        t0[4] := 10;
        t0[5] := 20;
        t0[6] := 0;
        readln(time);
        time := time+'/';
        i := 1;
        j := 1;
        while time[j] <> '/' do inc(j);
        val(copy(time,i,j-i),t1[1]);
        inc(j);
        i := j;
        while time[j] <> '/' do inc(j);
        val(copy(time,i,j-i),t1[2]);
        inc(j);
        i := j;
        while time[j] <> '/' do inc(j);
        val(copy(time,i,j-i),t1[3]);
        inc(j);
        i := j;
        while time[j] <> '/' do inc(j);
        val(copy(time,i,j-i),t1[4]);
        inc(j);
        i := j;
        while time[j] <> '/' do inc(j);
        val(copy(time,i,j-i),t1[5]);
        inc(j);
        i := j;
        while time[j] <> '/' do inc(j);
        val(copy(time,i,j-i),t1[6]);
        for i := 1 to 6 do
        if t0[i] > t1[i] then
        begin
                t2 := t1;
                t1 := t0;
                t0 := t2;
                break;
        end;
        fillchar(t2,sizeof(t2),0);
        t2[6] := t1[6]-t0[6];
        if t2[6] < 0 then
        begin
                dec(t1[5]);
                t2[6] := t2[6]+60;
        end;
         t2[5] := t1[5]-t0[5];
        if t2[5] < 0 then
        begin
                dec(t1[4]);
                t2[5] := t2[5]+60;
        end;
        t2[4] := t1[4]-t0[4];
        if t2[4] < 0 then
        begin
                dec(t1[3]);
                t2[4] := t2[4]+24;
        end;

end.
