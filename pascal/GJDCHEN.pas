program GJDCHEN;
type
        arr = array[0..1000] of longint;
var
        a,b,c:arr;
        st,s1,s2:string;

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
        write(a[a[0]],',');//不要逗号可以去掉
        for i := a[0]-1 downto 1 do
        begin
                bl(a[i]);
                write(a[i],',');
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

function        s2v(st:string):arr;//将输入字符串转换为数组
var
        temp:arr;
        i,l:integer;
begin
        fillchar(temp,sizeof(temp),0);
        l := length(st);
        while l mod 4 <> 0 do//狂补零
        begin
                st := '0'+st;
                inc(l);
        end;
        l := l div 4;
        temp[0] := l;
        for i :=  1 to l do     val(copy(st,4*(i-1)+1,4),temp[l+1-i]);//截数字
        exit(temp);
end;

begin
        fillchar(a,sizeof(a),0);
        fillchar(b,sizeof(b),0);
        readln(st);
        s1 := copy(st,1,pos(' ',st)-1);
        s2 := copy(st,pos(' ',st)+1,length(st)-pos(' ',st));
        a := s2v(s1);
        b := s2v(s2);
        c := chen(a,b);
        outp(a);
        outp(b);
        outp(c);
end.
