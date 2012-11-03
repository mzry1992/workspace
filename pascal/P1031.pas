var
        a,star:string;
        h:array[0..99971] of boolean;

procedure work;
function ELFHash(st:string):longint;
var
        num,i,l,g:longint;
begin
        l := length(st);
        num := 0;
        for i := 1 to l do
        begin
                num := (num shl 4)+ord(st[i]);
                g := num and ($f0000000);
                if g > 0 then num := num xor (g shr 24);
                num := num and (not g);
        end;
        num := num mod 99971;
        exit(num);
end;

procedure dfs(now:string);
var
        i,j,k:longint;
begin
if h[ELFHash(now)] then exit;

end;
begin
        fillchar(h,sizeof(h),false);
        readln(a);
        h[ELFHash(a)] := true;
        star := 'Begin the Escape execution at the Break of Dawn';
        dfs(a);
end;

begin
        work;
end.