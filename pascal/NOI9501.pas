var
        cs,bcs,temp:longint;
begin
        for bcs := 1000 to 9999 do
        begin
                for cs := 10 to 99 do
                if cs * 8 in [10..99] then
                if (cs * 8) div 10 = (bcs div 1000) then
                if (bcs - cs * 8 * 100 <= 999) then
                if (bcs - cs * 8 * 100 >= 100) then
                if cs * 9 >= 100 then
                if cs * 9 <= 999 then
                if bcs - cs * 8 * 100 - cs * 9 = 1 then
                begin
                        writeln('    809');
                        writeln('   ----');
                        writeln(cs,')',bcs);
                        writeln('   ',cs*8);
                        writeln('   ----');
                        writeln('    ',bcs-cs*8*100);
                        writeln('    ',cs*9);
                        writeln('   ----');
                        writeln('      1');
                end;
        end;
end.
