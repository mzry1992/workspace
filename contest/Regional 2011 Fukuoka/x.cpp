const AllowNode=1000000;
var
count,ll,pl:array[0..100] of longint;
a,final:array[0..100] of string[20];
wd:array[0..20,0..20] of string[20];
ans,pairing:array[0..100] of longint;
pair:array['A'..'Z'] of char;
found,multi:boolean;
len,NodeCount:longint;

procedure dfs(cur:longint);
var tmp:array['A'..'Z'] of char;
    i,j,lc:longint;
    flag:boolean;
begin if cur>len then
	begin if found then begin multi:=true; exit; end;
		found:=true; ans:=pairing;
		//writeln('Solution Found!');
		exit;
	end;
	inc(NodeCount);
	if (found)and(NodeCount>AllowNode) then exit;
	lc:=ll[cur]; tmp:=pair;
	for i:=1 to count[lc] do
	begin flag:=true;
		for j:=1 to lc do
		begin if (pair[a[cur,j]]<>' ')and(pair[a[cur,j]]<>wd[lc,i,j]) then
			begin flag:=false;
				break;
			end;
			if (pair[wd[lc,i,j]]<>' ')and(pair[wd[lc,i,j]]<>a[cur,j]) then
			begin flag:=false;
				break;
			end;
			pair[wd[lc,i,j]]:=a[cur,j];
			pair[a[cur,j]]:=wd[lc,i,j];
		end;
		if not flag then begin pair:=tmp; continue; end;
		pairing[cur]:=i;
		dfs(cur+1);
		if (multi)or((NodeCount>AllowNode)and(found)) then exit;
		pair:=tmp;
	end;
end;

var
s:string;

procedure lemon();
var n,i,i2,j,temp:longint;
    ch:char;
begin readln(n); if n=0 then halt;
	NodeCount:=0;
	fillchar(count,sizeof(count),0);
	for i:=1 to n do 
	begin readln(s); inc(count[length(s)]);
		wd[length(s),count[length(s)]]:=s;
	end;
	readln(s);
	s:=copy(s,1,length(s)-1)+' ';
	i:=1; len:=0;
	while i<=length(s) do
	begin i2:=i;
		while s[i]<>' ' do inc(i);
		inc(len); a[len]:=copy(s,i2,i-i2); pl[len]:=len;
		inc(i);
	end;
	for i:=1 to len-1 do
		for j:=i+1 to len do
			if (count[length(a[i])]>count[length(a[j])])or((count[length(a[i])]=count[length(a[j])])and(random(2)=0)) then
			begin s:=a[i];
				a[i]:=a[j];
				a[j]:=s;
				temp:=pl[i];
				pl[i]:=pl[j];
				pl[j]:=temp;
			end;
	for i:=1 to len do ll[i]:=length(a[i]);
	for ch:='A' to 'Z' do pair[ch]:=' ';
	multi:=false; found:=false;
	dfs(1);
	if multi then begin writeln('-.'); exit; end;
	for i:=1 to len do final[pl[i]]:=wd[length(a[i])][ans[i]];
	for i:=1 to len do
	begin write(final[i]);
		if i=len then writeln('.') else write(' ');
	end;
end;
	
begin
while true do lemon();
end.