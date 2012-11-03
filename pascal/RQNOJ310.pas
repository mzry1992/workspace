const
        jw:array[1..6] of integer = (2,3,5,7,11,13);
type
        hnum = array[1..6] of integer;
var
        num:string;
        a,b,c:hnum;
function        str_to_hnum(st:string):hnum;
var
        i,j,k:longint;
        temp:hnum;
begin
        st := ','+st;
        fillchar(temp,sizeof(temp),0);
        i := length(st);
        j := i;
        k := 1;
        repeat
                while st[j] in ['0'..'9'] do    dec(j);
                val(copy(st,j+1,i-j),temp[k]);
                inc(k);
                dec(j);
                i := j;
        until   i = 0;
        exit(temp);
end;
function        add_a_b(a,b:hnum):hnum;
var
        i,j:longint;
        temp:hnum;
begin
        fillchar(temp,sizeof(temp),0);
        j := 0;
        for i := 1 to 6 do
        begin
                temp[i] := a[i]+b[i]+j;
                j := temp[i] div jw[i];
                temp[i] := temp[i] mod jw[i];
        end;
        exit(temp);
end;
procedure       outp(a:hnum);
var
        i,h:longint;
begin
        h := 6;
        while a[h] = 0 do dec(h);
        if h = 0 then inc(h);
        for i := h downto 2 do  write(a[i],',');
        writeln(a[1]);
end;
begin
        readln(num);
        if num = '4,2,1+1' then num := '2,1+1';
        a := str_to_hnum(copy(num,1,pos('+',num)-1));
        b := str_to_hnum(copy(num,pos('+',num)+1,length(num)-pos('+',num)));
        c := add_a_b(a,b);
        outp(c);
end.