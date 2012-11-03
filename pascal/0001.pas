{$G+}
program flames;
  uses
    crt;
  const
    palette : array [1..768] of byte = (
      0,    0,    0,    0,    0,    24,    0,    0,    24,    0,    0,    28,
      0,    0,   32,    0,    0,    32,    0,    0,    36,    0,    0,    40,
      8,    0,   40,   16,    0,    36,   24,    0,    36,   32,    0,    32,
     40,    0,   28,   48,    0,    28,   56,    0,    24,   64,    0,    20,
     72,    0,   20,   80,    0,    16,   88,    0,    16,   96,    0,    12,
    104,    0,    8,  112,    0,     8,  120,    0,     4,  128,    0,     0,
    128,    0,    0,  132,    0,     0,  136,    0,     0,  140,    0,     0,
    144,    0,    0,  144,    0,     0,  148,    0,     0,  152,    0,     0,
    156,    0,    0,  160,    0,     0,  160,    0,     0,  164,    0,     0,
    168,    0,    0,  172,    0,     0,  176,    0,     0,  180,    0,     0,
    184,    4,    0,  188,    4,     0,  192,    8,     0,  196,    8,     0,
    200,   12,    0,  204,   12,     0,  208,   16,     0,  212,   16,     0,
    216,   20,    0,  220,   20,     0,  224,   24,     0,  228,   24,     0,
    232,   28,    0,  236,   28,     0,  240,   32,     0,  244,   32,     0,
    252,   36,    0,  252,   36,     0,  252,   40,     0,  252,   40,     0,
    252,   44,    0,  252,   44,     0,  252,   48,     0,  252,   48,     0,
    252,   52,    0,  252,   52,     0,  252,   56,     0,  252,   56,     0,
    252,   60,    0,  252,   60,     0,  252,   64,     0,  252,   64,     0,
    252,   68,    0,  252,   68,     0,  252,   72,     0,  252,   72,     0,
    252,   76,    0,  252,   76,     0,  252,   80,     0,  252,   80,     0,
    252,   84,    0,  252,   84,     0,  252,   88,     0,  252,   88,     0,
    252,   92,    0,  252,   96,     0,  252,   96,     0,  252,  100,     0,
    252,  100,    0,  252,  104,     0,  252,  104,     0,  252,  108,     0,
    252,  108,    0,  252,  112,     0,  252,  112,     0,  252,  116,     0,
    252,  116,    0,  252,  120,     0,  252,  120,     0,  252,  124,     0,
    252,  124,    0,  252,  128,     0,  252,  128,     0,  252,  132,     0,
    252,  132,    0,  252,  136,     0,  252,  136,     0,  252,  140,     0,
    252,  140,    0,  252,  144,     0,  252,  144,     0,  252,  148,     0,
    252,  152,    0,  252,  152,     0,  252,  156,     0,  252,  156,     0,
    252,  160,    0,  252,  160,     0,  252,  164,     0,  252,  164,     0,
    252,  168,    0,  252,  168,     0,  252,  172,     0,  252,  172,     0,
    252,  176,    0,  252,  176,     0,  252,  180,     0,  252,  180,     0,
    252,  184,    0,  252,  184,     0,  252,  188,     0,  252,  188,     0,
    252,  192,    0,  252,  192,     0,  252,  196,     0,  252,  196,     0,
    252,  200,    0,  252,  200,     0,  252,  204,     0,  252,  208,     0,
    252,  208,    0,  252,  208,     0,  252,  208,     0,  252,  208,     0,
    252,  212,    0,  252,  212,     0,  252,  212,     0,  252,  212,     0,
    252,  216,    0,  252,  216,     0,  252,  216,     0,  252,  216,     0,
    252,  216,    0,  252,  220,     0,  252,  220,     0,  252,  220,     0,
    252,  220,    0,  252,  224,     0,  252,  224,     0,  252,  224,     0,
    252,  224,    0,  252,  228,     0,  252,  228,     0,  252,  228,     0,
    252,  228,    0,  252,  228,     0,  252,  232,     0,  252,  232,     0,
    252,  232,    0,  252,  232,     0,  252,  236,     0,  252,  236,     0,
    252,  236,    0,  252,  236,     0,  252,  240,     0,  252,  240,     0,
    252,  244,    0,  252,  244,     0,  252,  244,     0,  252,  248,     0,
    252,  248,    0,  252,  248,     0,  252,  248,     0,  252,  252,     0,
    252,  252,    4,  252,  252,     8,  252,  252,    12,  252,  252,    16,
    252,  252,   20,  252,  252,    24,  252,  252,    28,  252,  252,    32,
    252,  252,   36,  252,  252,    40,  252,  252,    40,  252,  252,    44,
    252,  252,   48,  252,  252,    52,  252,  252,    56,  252,  252,    60,
    252,  252,   64,  252,  252,    68,  252,  252,    72,  252,  252,    76,
    252,  252,   80,  252,  252,    84,  252,  252,    84,  252,  252,    88,
    252,  252,   92,  252,  252,    96,  252,  252,   100,  252,  252,   104,
    252,  252,  108,  252,  252,   112,  252,  252,   116,  252,  252,   120,
    252,  252,  124,  252,  252,   124,  252,  252,   128,  252,  252,   132,
    252,  252,  136,  252,  252,   140,  252,  252,   144,  252,  252,   148,
    252,  252,  152,  252,  252,   156,  252,  252,   160,  252,  252,   164,
    252,  252,  168,  252,  252,   168,  252,  252,   172,  252,  252,   176,
    252,  252,  180,  252,  252,   184,  252,  252,   188,  252,  252,   192,
    252,  252,  196,  252,  252,   200,  252,  252,   204,  252,  252,   208,
    252,  252,  208,  252,  252,   212,  252,  252,   216,  252,  252,   220,
    252,  252,  224,  252,  252,   228,  252,  252,   232,  252,  252,   236,
    252,  252,  240,  252,  252,   244,  252,  252,   248,  252,  252,   252,
    252,  252,  240,  252,  252,   244,  252,  252,   248,  252,  252,   252);
    radius    = 1;
    frequency = 2;
    angleinc  = 3 * pi / frequency;

  var
    count       : word;
    delta       : integer;
    path        : array[0..199] of word;
    buffer      : array[0..102,0..159] of integer;

  procedure buildpath;
    var
      count     : byte;
      currangle : real;
    begin
      currangle := pi;
      for count := 0 to 199 do
        begin
          path[count] := 320 + round(radius*sin(currangle));
          if path[count] mod 2 <> 0 then
            if path[count] > 320 then
              dec(path[count])
            else
              inc(path[count]);
          currangle := currangle + angleinc;
        end;
    end;

  begin
    randomize;
    buildpath;
    asm
      mov   ax,13h
      int   10h
      xor   ax,ax
      mov   cx,768
      mov   dx,03C8h
      mov   si,offset palette
      out   dx,al
      inc   dx
    @l1:
      mov   bl,[si]
      shr   bl,2
      mov   [si],bl
      outsb
      dec   cx
      jnz   @l1
      mov   ax,seg buffer
      mov   es,ax
      mov   di,offset buffer
      mov   cx,8109
      xor   ax,ax
      rep   stosw
    end;
    repeat
      asm
        mov   bx,1
        mov   si,offset path
        mov   cx,16160
        mov   di,offset buffer
        add   di,320
      @l2:
        mov   ax,ds:[di-2]
        add   ax,ds:[di]
        add   ax,ds:[di+2]
        add   ax,ds:[di+320]
        shr   ax,2
        jz    @l3
        dec   ax
      @l3:
        push  di
        sub   di,ds:[si]
        mov   word ptr ds:[di],ax
        pop   di
        inc   di
        inc   di
        inc   bx
        cmp   bx,320
        jle   @l4
        mov   bx,1
        inc   si
        inc   si
      @l4:
        dec   cx
        jnz   @l2
      end;
      for count := 0 to 159 do
        begin
          if random < 0.4 then
            delta := random(2)*255;
          buffer[101,count] := delta;
          buffer[102,count] := delta;
        end;
      asm
        mov   si,offset buffer
        mov   ax,0A000h
        mov   es,ax
        xor   di,di
        mov   dx,100
      @l5:
        mov   bx,2
      @l6:
        mov   cx,160
      @l7:
        mov   al,ds:[si]
        mov   ah,al
        mov   es:[di],ax
        inc   di
        inc   di
        inc   si
        inc   si
        dec   cx
        jnz   @l7
        sub   si,320
        dec   bx
        jnz   @l6
        add   si,320
        dec   dx
        jnz   @l5
      end;
    until keypressed;
    asm
      mov   ax,03h
      int   10h
    end;
  end.
