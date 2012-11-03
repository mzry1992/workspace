var
        a,b:string;
        ka,kb:char;
begin
        readln(a);
        while a <> '-1' do
        begin
                readln(b);
                a := a+' ';
                b := b+' ';
                ka := a[pos(' ',a)-1];
                kb := b[pos(' ',b)-1];
                if (ka in ['2','3','7','8']) and (kb in ['2','3','7','8']) then
                        writeln('SheepDaddy')
                else
                        writeln('MengMeng');
                readln(a);
        end;
end.
