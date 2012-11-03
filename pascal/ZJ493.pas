const
        jz = 10000;
type
        arr = array[0..10000] of longint;
var
        a,n,t:longint;
        base,ans:arr;

procedure       bl(i:longint);//补零
begin
        if (1000 <= i ) and (i < 10000) then    exit;
        if (100  <= i ) and (i < 1000 ) then    begin   write('0');     exit;   end;
        if (10   <= i ) and (i < 100  ) then    begin   write('00');     exit;   end;
        if (0    <= i ) and (i < 10   ) then    begin   write('000');     exit;   end;
end;

procedure       outp(a:arr);//输出
var
        i:longint;
begin
        while a[a[0]] = 0 do    dec(a[0]);
        if a[0] = 0 then inc(a[0]);
        write(a[a[0]]);//不要逗号可以去掉
        for i := a[0]-1 downto 1 do
        begin
                bl(a[i]);
                write(a[i]);
        end;
        writeln;
end;

function        long(a:arr):integer;//判断长度
var
        i:integer;
begin
        i := 1000;
        while a[i] = 0 do dec(i);
        exit(i);
end;

function        chen(a,b:arr):arr;//乘法
var
        i,j:integer;
        temp:arr;
begin
        fillchar(temp,sizeof(temp),0);
        for i :=  1 to a[0] do
        for j :=  1 to b[0] do
        begin
                temp[i+j-1] := temp[i+j-1]+a[i]*b[j];
                temp[i+j] := temp[i+j]+temp[i+j-1] div 10000;
                temp[i+j-1] := temp[i+j-1] mod 10000;
        end;
        temp[0] := long(temp);
        exit(temp);
end;

procedure       roll(i:longint);
var
        stack:array[0..31] of longint;
begin
        stack[0] := 0;
        while i > 1 do
        begin
                inc(stack[0]);
                stack[stack[0]] := i and 1;
                i := i shr 1;
        end;
        ans := base;
        while stack[0] > 0 do
        begin
                ans := chen(ans,ans);
                if stack[stack[0]] = 1 then    ans := chen(ans,base);
                dec(stack[0]);
        end;
end;

begin
        assign(output,'ZJ493.txt');
        rewrite(output);
        readln(a,n);
        t := abs(a);
        base[0] := 0;
        while t <> 0 do
        begin
                inc(base[0]);
                base[base[0]] := t mod jz;
                t := t div jz;
        end;
        fillchar(ans,sizeof(ans),0);
        roll(n);
        if a < 0 then write('-');
        outp(ans);
        close(output);
end.


