var
        i_p,i_k,i_s,i,j,k,le,temp:longint;
        st,str:string;
        dic:array[1..6] of string;
        len:array[1..6] of longint;
        tot:array[1..200,1..200] of longint;
procedure       getans;
var
        f:array[1..200,1..40] of longint;
        i,j,k,le:longint;
begin
        le := length(st);
        fillchar(f,sizeof(f),0);
        for i := 1 to le do
                f[i,1] := tot[1,i];
        for j := 2 to i_k do
        for i := j to le-i_k+j do
        begin
                f[i,j] := -maxlongint;
                for k := j-1 to i-1 do
                if f[k,j-1]+tot[k+1,i] > f[i,j] then
                        f[i,j] := f[k,j-1]+tot[k+1,i];
        end;
        writeln(f[le,i_k]);
end;
begin
        st := '';
        readln(i_p,i_k);
        for i := 1 to i_p do
        begin
                readln(str);
                st := st+str;
        end;
        i_p := i_p * 20;
        readln(i_s);
        for i := 1 to i_s do
        begin
                readln(dic[i]);
                len[i] := length(dic[i]);
        end;
        getans;
end.
