program calculater;
const
        max_stack = 100;
type
        num_stacktype = record
                stack:array[1..max_stack] of double;
                top:0..max_stack;
        end;
        opt_stacktype = record
                stack:array[1..2*max_stack] of char;
                top:0..2*max_stack;
        end;
var
        optr:opt_stacktype;
        opnd:num_stacktype;
        expr:ansistring;
        o_expr:array[1..3*max_stack] of ansistring;
begin
        readln(expr);
        expend_expr(expr);
end.
