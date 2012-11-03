program lx;
  uses
    crt;

  var
    b,c,v,p1,s,n,i,j,q,m,m1,x,r,d : integer;
    p,a,t : array[0..5000] of integer;

  const f1=5;
  const f2=239;
  procedure divide(d:integer);
    begin
      r:=0;
      for j:=0 to m do begin
        v:=r*10+p[j];
        q:=v div d;
        r:=v mod d;
        p[j]:=q;
      end;
    end;

  procedure dividea(d : integer);
    begin
      r:=0;
      for j:=0 to m do begin
        v:= r*10+a[j];
        q:=v div d;
        r:=v mod d;
        a[j]:=q;
      end;
    end;

  procedure subt;
    begin
      b:=0;
      for j:=m downto 0 do
        if t[j]>=a[j]
          then t[j]:=t[j]-a[j]
          else begin
            t[j]:=10+t[j]-a[j];
            t[j-1]:=t[j-1]-1;
          end;
      for j:=0 to m do a[j]:=t[j];
    end;

  procedure suba;
    begin
      for j:=m downto 0 do
      if p[j]>=a[j]
        then p[j]:=p[j]-a[j]
        else begin
          p[j]:=10+p[j]-a[j];
          p[j-1]:=p[j-1]-1;
        end;
      for j:= m downto 0 do a[j]:=p[j];
    end;

  procedure clearp;
    begin
      for j:=0 to m do p[j]:=0;
    end;

  procedure adjust;
    begin
      p[0]:=3;
      p[m]:=10;
      for j:=1 to m-1 do p[j]:=9;
    end;

  procedure adjust2;
    begin
      p[0]:=0;
      p[m]:=10;
      for j:=1 to m-1 do p[j]:=9;
    end;

  procedure mult4;
    begin
      c:=0;
      for j:=m downto 0 do begin
        p1:=4*a[j]+c;
        a[j]:=p1 mod 10;
        c:=p1 div 10;
      end;
    end;

  procedure savea;
    begin
      for j:=0 to m do
        t[j]:=a[j];
    end;

  procedure term1;
    begin
      i:=m*2+1;
      a[0]:=4;
      dividea(i*25);
      while i>3 do begin
        i:=i-2;
        clearp;
        p[0]:=4;
        divide(i);
        suba;
        dividea(25);
      end;
      clearp;
      adjust;
      suba;
      dividea(5);
      savea;
    end;

  procedure term2;
    begin
      i:=m+m+1;
      a[0]:=1;
      dividea(i);
      dividea(239);
      dividea(239);
      while i>3 do begin
        i:=i-2;
        clearp;
        p[0]:=1;
        divide(i);
        suba;
        dividea(239);
        dividea(239);
      end;
      clearp;
      adjust2;
      suba;
      dividea(239);
      subt;
    end;


  begin
  clrscr;
    writeln('Input No. Decimal Places');
    readln(m1);
    m:=m1+4;
    for j:=0 to m do begin
      a[j]:=0;
      t[j]:=0;
    end;
    term1;
    term2;
    mult4;
    writeln;
    write('Pi = 3.');
    for j:=1 to m1 do begin
      write(a[j]);
      if j mod 5 =0 then write('  ');
      if j mod 50=0 then write('          ');
      if j mod 1000 = 0 then
      begin
      readln;
      clrscr;
      end;
    end;
    writeln;
    repeat until keypressed ;
  end.
