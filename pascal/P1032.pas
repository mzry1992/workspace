var
        nu,st,tk:string;
        k,n,top:longint;
        d:array[1..1000] of string;
        ans:boolean;

begin
        readln(st);
        nu := copy(st,1,pos(' ',st)-1);
        tk := copy(st,pos(' ',st)+1,length(st)-length(nu)-1);
        val(tk,k);
        nu := copy(nu,length(nu)+1-k,k);
        top := 1;
        d[top] := nu;
        ans := false;
        begin
                inc(top);
                d[top] := mul(d[top-1],nu);
                writeln(d[top]);
        end;
end.