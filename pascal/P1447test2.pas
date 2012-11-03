type arr = array[0..1000] of longint;
var
        st,tem,l,r,te:ansistring;
        a,b,c,d,e,f,temp:arr;
        step:integer;

function long(a:arr):integer;
var
        i:integer;
begin
        i := 1000;
        while (a[i] = 0) and ( i > 0 ) do dec(i);
        long := i;
end;

function s2v(st:ansistring):arr;
var
        i,l:integer;
begin
        fillchar(temp,sizeof(temp),0);
        l := length(st);
        temp[0] := l;
        for i := 1 to l do
                temp[l+1-i] := ord(st[i])-ord('0');
        s2v := temp;
end;

function v2s(a:arr):ansistring;
var
        i,l:integer;
        temp:ansistring;
begin
        l:=a[0];
        if l = 0 then begin v2s := '0'; exit; end;
        temp := '';
        for i := 1 to l do temp := temp+'0';
        for i := l downto 1 do
        temp[i] := chr(a[l+1-i]+ord('0'));
        v2s := temp;
end;

function times(a:arr):arr;
var
        i,j:integer;
begin
        fillchar(temp,sizeof(temp),0);
        for i := 1 to a[0] do
        for j := 1 to a[0] do
        begin
                temp[i+j-1] := temp[i+j-1]+a[i]*a[j];
                temp[i+j] := temp[i+j]+temp[i+j-1] div 10;
                temp[i+j-1] := temp[i+j-1] mod 10;
        end;
        temp[0]:=long(temp);
        times := temp;
end;

function half(a:arr):arr;
var
        i,j:integer;
begin
        fillchar(temp,sizeof(temp),0);
        j := 0;
        for i := a[0] downto 1 do
        begin
                temp[i] := (a[i]+j*10) shr 1;
                j := a[i] and 1;
        end;
        temp[0] := a[0];
        if temp[temp[0]] = 0 then dec(temp[0]);
        half := temp;
end;

function max(a,b:integer):integer;
begin
        if a > b then exit(a);
        exit(b);
end;

function jia(a,b:arr):arr;
var
        i,j:integer;
begin
        fillchar(temp,sizeof(temp),0);
        j := 0;
        for i := 1 to max(a[0],b[0]) do
        begin
                temp[i] := a[i]+b[i]+j;
                j := temp[i] div 10;
                temp[i] := temp[i] mod 10;
        end;
        if j > 0 then
                temp[max(a[0],b[0])+1] := j;
        temp[0] := long(temp);
        exit(temp);
end;

function big(a,b:ansistring):integer;
var
        i:integer;
begin
        if length(a) > length(b) then exit(0);
        if length(a) < length(b) then exit(1);
        for i := 1 to length(a) do
                if a[i] > b[i] then exit(0)
                else
                if a[i] < b[i] then exit(1);
        exit(2);
end;

begin
        readln(st);
        l := '0';
        r := st;
        while big(l,r) = 1 do
        begin
                inc(step);
                a := s2v(l);
                b := s2v(r);
                c := jia(a,b);
                e := half(c);
                te := v2s(e);
                f := times(e);
                tem := v2s(f);
                case big(tem,st)       of
                        0       :       r := te;
                        1       :       l := te;
                        2       :       begin   l := te;    r := te;      end;
                end;
                f := jia(a,s2v('1'));
                tem := v2s(f);
                if tem = r then
                        r := l;
        end;
        writeln(r);
end.

