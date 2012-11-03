var
        n:longint;
        a1,a2,a3:string;
        u:array['A'..'Z'] of integer;
        use:array[0..25] of boolean;
        so:array[1..26] of char;
        us:array['A'..'Z'] of boolean;
        maxn1,maxn2,maxn3:char;

function        check:boolean;
var
        i,j:integer;
begin
        j := 0;
        for i := n downto 1 do
        if (u[a1[i]]+u[a2[i]]+j) mod n = u[a3[i]] then
                j := (u[a1[i]]+u[a2[i]]+j) div n
        else
                exit(false);
        exit(true);
end;

function        canuse:boolean;
var
        i,t1,t2:integer;
begin
        for i := n downto 1 do
        begin
                {a+b=c}
                if us[a1[i]] and us[a2[i]] and us[a3[i]] then
                begin
                        if ((u[a1[i]]+u[a2[i]]+1) mod n <> u[a3[i]] ) and ((u[a1[i]]+u[a2[i]]) mod n <> u[a3[i]]) then
                                exit(false);
                end
                else
                {a+b=?}

                if us[a1[i]] and us[a2[i]] then
                begin
                        t1 := (u[a1[i]]+u[a2[i]]) mod n;
                        t2 := (u[a1[i]]+u[a2[i]]+1) mod n;
                        if use[t1] and use[t2] then exit(false);
                end
                else
                {a+?=c}
                if us[a1[i]] and us[a3[i]] then
                begin
                        t1 := (u[a3[i]]-u[a1[i]]+n) mod n;
                        t2 := (t1-1) mod n;
                        if use[t1] and use[t2] then exit(false);
                end
                else
                {?+b=c}
                if us[a2[i]] and us[a3[i]] then
                begin
                        t1 := (u[a3[i]]-u[a2[i]]+n) mod n;
                        t2 := (t1-1) mod n;
                        if use[t1] and use[t2] then exit(false);
                end;
        end;
        exit(true);
end;

procedure       dfs(dep:integer);
var
        i:integer;
        ch:char;
begin
        if dep = n+1 then
        begin
                if check then
                begin
                        for ch := 'A' to maxn1 do    write(u[ch],' ');
                        writeln(u[maxn2]);
                        close(input);
                        close(output);
                        halt;
                end;
                exit;
        end;
        for i := n-1 downto 0 do
        if not use[i] then
        begin
                use[i] := true;
                u[so[dep]] := i;
                us[so[dep]] := true;
                if canuse then  dfs(dep+1);
                use[i] := false;
                us[so[dep]] := false;
        end;
end;

procedure       sort;
var
        uu:array['A'..'Z'] of boolean;
        tt,i:integer;
begin
        fillchar(uu,sizeof(uu),false);
        tt := 0;
        for i := n downto 1 do
        begin
                if not uu[a1[i]] then
                begin
                        uu[a1[i]] := true;
                        inc(tt);
                        so[tt] := a1[i];
                end;
                if not uu[a2[i]] then
                begin
                        uu[a2[i]] := true;
                        inc(tt);
                        so[tt] := a2[i];
                end;
                if not uu[a3[i]] then
                begin
                        uu[a3[i]] := true;
                        inc(tt);
                        so[tt] := a3[i];
                end;
        end;
end;

begin
        assign(input,'alpha.in');
        assign(output,'alpha.out');
        reset(input);
        rewrite(output);
        fillchar(use,sizeof(use),false);
        fillchar(us,sizeof(us),false);
        readln(n);
        readln(a1);
        readln(a2);
        readln(a3);
        sort;
        maxn1 := chr(n+ord('A')-2);
        maxn2 := chr(n+ord('A')-1);
        dfs(1);
end.