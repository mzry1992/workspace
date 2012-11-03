var
	num,stemp:ansistring;
	m,k,i,j,l,ntemp,amax,kmax,amin,kmin:longint;
	g:array[1..1000,1..1000] of longint;
        fb,fs:array[1..1000,0..1000] of longint;
function        max(a,b:longint):longint;
begin
        if a > b then exit(a);
        exit(b);
end;
function        min(a,b:longint):longint;
begin
        if a < b then exit(a);
        exit(b);
end;
begin
        assign(input,'P1455.in');
        reset(input);
        assign(output,'P1455.out');
        rewrite(output);
	readln(num);
	readln(m);
	l := length(num);
	for i := 1 to l do
	for j := i to l do
	begin
		stemp := copy(num,i,j-i+1);
		if length(stemp) > 2 then
			stemp := copy(stemp,length(stemp)-1,2);
		val(stemp,ntemp);
		g[i,j] := ntemp mod m;
	end;
        for i := 1 to l do
        begin
                fb[i,0] := g[1,i];
                fs[i,0] := g[1,i];
        end;
        for i := 1 to l do
        for j := 1 to i-1 do
        begin
                fb[i,j] := -maxlongint;
                fs[i,j] := maxlongint;
                for k := 1 to i-1 do
                begin
                        fb[i,j] := max(fb[i,j] mod m,fb[k,j-1]*g[k+1,i] mod m);
                        fs[i,j] := min(fs[i,j] mod m,fs[k,j-1]*g[k+1,i] mod m);
                end;
        end;
        amax := -maxlongint;
        kmax := 0;
        amin := maxlongint;
        kmin := 0;
        for i := 0 to l-1 do
        begin
                if fb[l,i] > amax then
                begin
                        amax := fb[l,i];
                        kmax := i;
                end;
                if fs[l,i] < amin then
                begin
                        amin := fs[l,i];
                        kmin := i;
                end;
        end;
        writeln(amin,' ',kmin,' ',amax,' ',kmax);
        close(input);
        close(output);
end.
