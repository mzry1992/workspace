var
        st,max,min:string;
        d:array[1..1000] of string;
        top,l:longint;
        ans:boolean;

procedure done(st:string;var max,min:string);
var
        i,j:longint;
        temp,temp2:string;
        ch:char;
begin
        temp := st;
        for i := 1 to l do
        for j := 1 to l do
        if temp[i] < temp[j] then
        begin
                ch := temp[i];  temp[i] := temp[j];     temp[j] := ch;
        end;
        temp2 := temp;
        for i := 1 to l do
                temp2[i] := temp[l+1-i];
        min := temp;
        max := temp2;
end;

function dec(s1,s2:string):string;
var
        i:longint;
        k:string;
begin
        k := s1;
        for i := l downto 1 do
        begin
                k[i] := chr(ord(s1[i])-ord(s2[i])+ord('0'));
                if k[i] < '0' then
                begin
                        k[i] := chr(ord(k[i])+10);
                        s1[i-1] := chr(ord(s1[i-1])-1);
                end;
        end;
        exit(k);
end;

function del(st:string):string;
var
        i:longint;
begin
        i := 1;
        while st[i] = '0' do inc(i);
        st := copy(st,i,l+1-i);
        if st = '' then st := '0';
        exit(st);
end;

procedure findans;
var
        i,j:longint;
begin
        for i := 1 to top-1 do
        if d[i] = d[top] then
        begin
                for j := i to top-1 do write(del(d[j]),' ');
                writeln;
                ans := true;
        end;
end;

begin
while not eof do
begin
        readln(st);
        l := length(st);
        top := 1;
        d[top] := st;
        ans := false;
        while not ans do
        begin
                inc(top);
                done(d[top-1],max,min);
                d[top] := dec(max,min);
                findans;
        end;
end;
end.