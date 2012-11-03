const
        a = true;
        b = true;
        c = false;
        d = true;
        e = false;
        f = 3;
begin
        writeln((a or b) and ( c or d) and e);
        writeln(((a or b) and c ) or d or e);
        writeln(a or (b and c and d and e));
        writeln((a or (b and c)) or d or e);
        writeln(f and 1);
        writeln(f or 1);
        writeln((f-1) and 1);
        writeln((f-1) or 1);
end.
