program P1629;
var
 left,right,num,kp:int64;
 a,sav:array[0..20] of integer;
 temp1:array[1..10000] of int64;
 temp2:array[1..10000] of int64;
 i,n,an1,an2,abc:longint;

function gcd(a,b:int64):int64;
 begin
    abc := abc+1;
    abc := abc-1;
    if b>a then begin a:=a+b; b:=a-b; a:=a-b; end;
    if b=0 then gcd:=a else gcd:=gcd(b,a mod b);
 end;

procedure work(p:integer);
 var
    i:integer;
    k,gbs:int64;
 begin
    gbs:=8;
    for i:=1 to p do
      begin
        if gbs<=right then gbs:=gbs*a[sav[i]] div gcd(gbs,a[sav[i]])
        else exit;
      end;
    k:= right div gbs - (left-1) div gbs;

    if p mod 2=1 then begin inc(an1); temp1[an1]:=k; end
                 else begin inc(an2); temp2[an2]:=k; end;
 end;

procedure opp(p,k:integer);
 var
    i:integer;
 begin
    if p>k then work(k)
    else for i:=sav[p-1]+1 to n-k+p do
      begin
        sav[p]:=i;
        opp(p+1,k);
      end;
 end;

begin
 an1:=0;
 an2:=0;
 read(n);
 for i:=1 to n do
    begin
      read(a[i]);
      if (a[i]=1) or (a[i]=2) or (a[i]=4) or (a[i]=8) then
        begin
          writeln(0);
          exit;
        end;
    end;
 read(left,right);
 num:= right div 8 - (left-1) div 8;
 a[0]:=8;
 for i:=1 to n do
    opp(1,i);
 kp:=an1;
 if an2>an1 then kp:=an2;
 for i:=1 to kp do
    begin
      if i<=an1 then num:=num-temp1[i];
      if i<=an2 then num:=num+temp2[i];
    end;
 writeln(num);
end.
