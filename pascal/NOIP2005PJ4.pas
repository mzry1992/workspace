type
        arr = array[1..250] of longint;
var
        readin,ttn,ttk,base,zero     :string;
        tk      :integer;

function s2v(st :string)        :arr;
var
        i       :integer;
        temp    :arr;
begin
        fillchar(temp,sizeof(temp),0);
        for i := 1 to tk do
                temp[tk+1-i] := ord(st[i])-ord('0');
        exit(temp);
end;

function v2s(a  :arr)   :string;
var
        i,l     :integer;
        temp    :string;
begin
        temp := zero;
        for i := tk downto 1 do
                temp[i] := chr(a[tk+1-i]+ord('0'));
        exit(temp);
end;

function        addzero(st      :string)        :string;
var
        temp    :string;
        l       :integer;
begin
        temp := st;
        l := length(st);
        while l < tk do
        begin
                inc(l);
                temp := '0'+temp;
        end;
        exit(temp);
end;

function chen(a,b       :string)        :string;
var
        ta,tb,tt        :arr;
        i,j     :integer;
        temp    :string;
begin
        ta := s2v(a);
        tb := s2v(b);
        fillchar(tt,sizeof(tt),0);
        for i := 1 to tk do
        for j := 1 to tk do
        begin
                tt[i+j-1] := tt[i+j-1]+ta[i]*tb[j];
                tt[i+j] := tt[i+j]+tt[i+j-1] div 10;
                tt[i+j-1] := tt[i+j-1] mod 10;
        end;
        temp := v2s(tt);
        exit(temp);
end;

begin
        readln(readin);
        ttn := copy(readin,1,pos(' ',readin)-1);
        ttk := copy(readin,pos(' ',readin)+1,length(readin)-pos(' ',readin));
        val(ttk,tk);
        base := addzero(copy(ttn,length(ttn)-tk+1,tk));
        zero := addzero('0');
        writeln(chen('123','1000'));
end.