const
        InputFileName = 'mzry_is_SB.in';
        OutputFileName = 'mzry_is_SB.out';
var
        fi,fo:text;
procedure       beginprogram;
begin
        assign(fi,InputFileName);
        assign(fo,OutputFileName);
        reset(fi);
        rewrite(fo);
end;
procedure       endprogram;
begin
        close(fi);
        close(fo);
        halt;
end;
begin
        beginprogram;
        {MAIN}
        endprogram;
end.
