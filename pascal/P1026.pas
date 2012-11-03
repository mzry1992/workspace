var
        n,k,i,j,head,tail,now,temp,a,b,ta,tb,tc:longint;
        f,d:array[1..2000] of longint;
        h:array[1..2048] of boolean;
        m:array[1..100,1..2] of longint;
begin
        readln(n);
        readln(k);
        for i := 1 to k do
        begin
                head := 0;      tail := 0;
                for j := 1 to n do
                begin
                        read(now);
                        head := head shl 1;     tail := tail shl 1;
                        if now = 1 then
                                head := head or 1;
                        if now = -1 then
                                tail := tail or 1;
                end;
                m[i,1] := head; m[i,2] := tail;
                readln;
        end;
        fillchar(h,sizeof(h),false);
        head := 1;      tail := 1;
        d[head] := 1 shl n - 1;        f[head] := 0;    h[1 shl n -1] := true;
        while head <= tail do
        begin
                now := d[head];
                for i := 1 to k do
                        begin
                                 a := m[i,1];
                                 b := m[i,2];
                                 temp := now;
                                 for j := 1 to n do
                                 begin
                                          ta := a shr (j-1) and 1;
                                          tb := b shr (j-1) and 1;
                                          tc := now shr (j-1) and 1;
                                          tc := tc - ta + tb;
                                          case tc of
                                          -1      :       temp := temp and not (1 shl (j-1));
                                          0       :       temp := temp and not (1 shl (j-1));
                                          1       :       temp := temp or (1 shl (j-1));
                                          2       :       temp := temp or (1 shl (j-1));
                                          end;
                                  end;
                                 if not h[temp] then
                                 begin
                                         inc(tail);
                                         d[tail] := temp;
                                         f[tail] := f[head] + 1;
                                         h[temp] := true;
                                         if temp = 0 then
                                         begin
                                                 writeln(f[tail]);
                                                 halt;
                                         end;
                                 end;
                        end;
                inc(head);
        end;
        writeln('The patient will be dead.');
end.