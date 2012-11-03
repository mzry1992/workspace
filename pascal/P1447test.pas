const
        maxw = 250;
type
        arr = array[0..250] of longint;
var
        st:string;
        ans,a,b:arr;

function long(a:arr):integer;
var
        i:integer;
begin
        i := maxw;
        while (a[i] = 0) and ( i > 0) do dec(i);
        exit(i);
end;

function s2v(st:string):arr;
var
        temp:arr;
        i,l:integer;
begin
        fillchar(temp,sizeof(temp),0);
        l := length(st);
        for i := 1 to l do
                temp[l+1-i] := ord(st[i])-ord('0');
        temp[0] := l;
        exit(temp);
end;

function v2s(a:arr):string;
var
        temp:string;
        i,l:integer;
begin
        l := a[0];
        if l = 0 then exit('0');
        temp := '';
        for i := 1 to l do      temp := temp+'0';
        for i := l downto 1 do
                temp[i] := chr(a[l+1-i]+ord('0'));
        exit(temp);
end;

function chen(a,b:arr):arr;
var
        i,j:integer;
        temp:arr;
        tt:string;
begin
        fillchar(temp,sizeof(temp),0);
        for i := 1 to a[0] do
        for j := 1 to b[0] do
        begin
                temp[i+j-1] := temp[i+j-1]+a[i]*b[i];
                temp[i+j] := temp[i+j]+temp[i+j-1] div 10;
                temp[i+j-1] := temp[i+j-1] mod 10;
        end;
        temp[0] := long(temp);
        exit(temp);
end;

begin
        readln(st);
        a := s2v(st);
        b := s2v(st);
        ans := chen(a,b);
        writeln(v2s(ans));
end.