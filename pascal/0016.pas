var
        a,b,c,d,e,f,g,h,i,t,k:longint;
        uu:array[1..9] of boolean;
begin
        for a := 1 to 9 do
        for b := 1 to 9 do
        for c := 1 to 9 do
        for d := 1 to 9 do
        for e := 1 to 9 do
        for f := 1 to 9 do
        for g := 1 to 9 do
        for h := 1 to 9 do
        for i := 1 to 9 do
        begin
                t := 0;
                fillchar(uu,sizeof(uu),false);
                uu[a] := true;
                uu[b] := true;
                uu[c] := true;
                uu[d] := true;
                uu[e] := true;
                uu[f] := true;
                uu[g] := true;
                uu[h] := true;
                uu[i] := true;
                for k := 1 to 9 do
                if uu[k] then inc(t);
                if t = 9 then
                if a+b+c = 15 then
                if d+e+f = 15 then
                if g+h+i = 15 then
                if a+d+g = 15 then
                if b+e+h = 15 then
                if c+f+i = 15 then
                if a+e+i = 15 then
                if c+e+g = 15 then
                        writeln(a,b,c,d,e,f,g,h,i);
        end;
end.
