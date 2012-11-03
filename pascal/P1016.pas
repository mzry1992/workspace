var p1,p2,p3,p4,p5,p6,p7,p8,p9,i:integer;
    a,b:array[1..9] of integer;
begin
readln(a[1],a[2],a[3]);
readln(a[4],a[5],a[6]);
readln(a[7],a[8],a[9]);
for p1:= 0 to 3 do
 for p2:= 0 to 3 do
  for p3:= 0 to 3 do
   for p4:= 0 to 3 do
    for p5:= 0 to 3 do
     for p6:= 0 to 3 do
      for p7:= 0 to 3 do
       for p8:= 0 to 3 do
        for p9:= 0 to 3 do
        begin
        b[1]:= ( a[1] + p1+p2+p4 ) mod 4 ;      {A}
        b[2]:= ( a[2] + p1+p2+p3+p5 ) mod 4 ;   {B}
        b[3]:= ( a[3] + p2+p3+p6 ) mod 4 ;      {C}
        b[4]:= ( a[4] + p1+p4+p5+p7 ) mod 4 ;   {D}
        b[5]:= ( a[5] + p1+p3+p5+p7+p9 ) mod 4 ;{E}
        b[6]:= ( a[6] + p3+p5+p6+p9 ) mod 4 ;   {F}
        b[7]:= ( a[7] + p4+p7+p8 ) mod 4 ;      {G}
        b[8]:= ( a[8] + p5+p7+p8+p9 ) mod 4 ;   {H}
        b[9]:= ( a[9] + p6+p8+p9 ) mod 4 ;      {I}
        if b[1]+b[2]+b[3]+b[4]+b[5]+b[6]+b[7]+b[8]+b[9] = 0 then
         begin
         for i:= 1 to p1 do write(1,' ');
         for i:= 1 to p2 do write(2,' ');
         for i:= 1 to p3 do write(3,' ');
         for i:= 1 to p4 do write(4,' ');
         for i:= 1 to p5 do write(5,' ');
         for i:= 1 to p6 do write(6,' ');
         for i:= 1 to p7 do write(7,' ');
         for i:= 1 to p8 do write(8,' ');
         for i:= 1 to p9 do write(9,' ');
         writeln;
         halt;
         end;
        end;
end.









