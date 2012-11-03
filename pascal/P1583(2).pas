const maxn=25;
var n,m,j,i,k,l,ii,x,y,len,smap:longint;
    g,h,s:array[0..maxn,0..maxn,0..maxn] of integer;
    map,z:array[0..maxn,0..maxn] of boolean;
    flag:boolean;
procedure dfs(x,y:longint);
var i,j,k:longint;
    ok:boolean;
begin
    if flag then exit;
    if map[x,y] then begin dfs(x+y div l,y mod l+1);exit; end;
    if x>l then
    begin
        if smap=l*l then flag:=true;
        exit;
    end;
    for i:=1 to l do
    if (x+i-1>l)or(y+i-1>l)or(g[x,y,i]>1) then break else
    if g[x,y,i]=1 then
    begin
        ok:=true;
        for j:=x to x+i-1 do
        if ok=false then break
        else
        for k:=y to y+i-1 do
        if map[j,k] then begin ok:=false;break; end;
        if ok then
        begin
            for j:=x to x+i-1 do
            for k:=y to y+i-1 do
            map[j,k]:=true;
            inc(smap,i*i);
            dfs(x+y div l,y mod l+1);
            dec(smap,i*i);
            for j:=x to x+i-1 do
            for k:=y to y+i-1 do
            map[j,k]:=false;
        end;
    end;
end;
Begin
    readln(m);
    for ii:=1 to m do
    begin
        readln(l,n);
        fillchar(z,sizeof(z),false);
        fillchar(g,sizeof(g),0);
        fillchar(h,sizeof(h),0);
        fillchar(s,sizeof(s),0);
        for i:=1 to n do
        begin
           readln(x,y);
           z[x,y]:=true;
           g[x,y,1]:=1;
        end;
        for i:=1 to l do
        for j:=1 to l do
        for k:=j to l do
        h[i,j,k]:=h[i,j,k-1]+g[i,k,1];
        for i:=1 to l do
        for j:=1 to l do
        for k:=j to l do
        s[i,j,k]:=s[i,j,k-1]+g[k,i,1];
        for len:=2 to l do
        for i:=1 to l-len+1 do
        for j:=1 to l-len+1 do
        g[i,j,len]:=g[i,j,len-1]+h[i+len-1,j,j+len-1]+s[j+len-1,i,i+len-1]-g[i+len-1,j+len-1,1];
        fillchar(map,sizeof(map),false);
        flag:=false; smap:=0;
        dfs(1,1);
        if flag then writeln('Yes') else writeln('No');
    end;
End.
