{$G+}
program lx;
  uses
    crt;
  var
    c: Byte;
    c2,c3,c4:word;
    sintab :array [0..127] of word;
    headptr:word absolute $0040:$001A;
    tailptr:word absolute $0040:$001C;
  begin
    for c := 0 to 127 do
      sintab[c] := trunc((sin((2 * Pi / 128) * c) + 1) * 135);
    c3 := 0;
    repeat
      asm cli end;
      repeat until (port[$3DA] and 8) > 0;
      repeat until (port[$3DA] and 8) = 0;
      for c4 := 0 to sintab[c3 and 127] do
        begin
          repeat until (port[$3DA] and 1) = 0;
          repeat until (port[$3DA] and 1) > 0;
        end;
      for c := 0 to 63 do begin
        repeat until (port[$3DA] and 1) > 0;
        port[$3C8] := 0;
        port[$3C9] := c;
        port[$3C9] := 0;
        port[$3C9] := 63-c;
        repeat until (port[$3DA] and 1) = 0;
      end;
      for c := 63 downto 0 do begin
        repeat until (port[$3DA] and 1) > 0;
        port[$3C8] := 0;
        port[$3C9] := c;
        port[$3C9] := 0;
        port[$3C9] := 63-c;
        repeat until (port[$3DA] and 1) = 0;
      end;
      inc(c3);
      asm sti end;
    until headptr <> tailptr;
    headptr := tailptr;
    port[$3C8] := 0;
    port[$3C9] := 0;
    port[$3C9] := 0;
    port[$3C9] := 0;
  end.



