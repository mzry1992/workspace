const
        InputFileName = 'mzry_is_SB.in';
        OutputFileName = 'mzry_is_SB.out';
procedure       beginprogram;
begin
        assign(input,InputFileName);
        assign(output,OutputFileName);
        reset(input);
        rewrite(output);
end;
procedure       endprogram;
begin
        close(input);
        close(output);
        halt;
end;
begin
        beginprogram;
        {MAIN}
        endprogram;
end.
