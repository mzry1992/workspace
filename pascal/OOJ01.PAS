Program Test;
Var
    fin, fout: text;
    a, b:integer;
Begin
    Assign(fin, 'plus.in'); Reset(fin);
    Assign(fout, 'plus.out'); Rewrite(fout);
    Readln(fin, a, b);
    Writeln(fout, a+b);
    Close(fout);
End.