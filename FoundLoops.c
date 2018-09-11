
//m4-1.4.18/src/builtin.c:1458:7

int len = strlen (str);
for (i = len; i > 1; i--)
    if (str[i - 1] != 'X')
       break;


//m4-1.4.18/src/builtin.c:1412:3

//len passed in separately

for (i = 0; len > 0 && i < 6; i++)
  if (pattern[len - i - 1] != 'X')
    break;


//m4-1.4.18/src/debug.c:60:7

for (level = 0; *opts; opts++)
        {
          switch (*opts)
            {
            case 'a':
              level |= DEBUG_TRACE_ARGS;
              break;

            case 'e':
              level |= DEBUG_TRACE_EXPANSION;
              break;

            case 'q':
              level |= DEBUG_TRACE_QUOTE;
              break;

            case 't':
              level |= DEBUG_TRACE_ALL;
              break;

            case 'l':
              level |= DEBUG_TRACE_LINE;
              break;

            case 'f':
              level |= DEBUG_TRACE_FILE;
              break;

            case 'p':
              level |= DEBUG_TRACE_PATH;
              break;

            case 'c':
              level |= DEBUG_TRACE_CALL;
              break;

            case 'i':
              level |= DEBUG_TRACE_INPUT;
              break;

            case 'x':
              level |= DEBUG_TRACE_CALLID;
              break;
	}
}

//m4-1.4.18/src/symtab.c:131:3
while ((ch = *ptr++) != '\0')
  val = (val << 7) + (val >> (sizeof (val) * CHAR_BIT - 7)) + ch;



//m4-1.4.18/src/clean-temp.c:175:3
  for (; *s; s++)
    h = *s + ((h << 9) | (h >> (SIZE_BITS - 9)));


//m4-1.4.18/lib/filenamecat-lgpl.c:40:3
  for (f += FILE_SYSTEM_PREFIX_LEN (f); ISSLASH (*f); f++)
    continue;


//m4-1.4.18/lib/memchr2.c:162:3

  for (; n > 0; --n, ++char_ptr)
    {
      if (*char_ptr == c1 || *char_ptr == c2)
        return (void *) char_ptr;
    }


//m4-1.4.18/lib/memchr2.c:62:3
  for (void_ptr = s;
       n > 0 && (uintptr_t) void_ptr % sizeof (longword) != 0;
       --n)
    {
      char_ptr = void_ptr;
      if (*char_ptr == c1 || *char_ptr == c2)
        return (void *) void_ptr;
      void_ptr = char_ptr + 1;
    }



//m4-1.4.18/lib/basename-lgpl.c:36:3

  while (ISSLASH (*base))
    base++;



//m4-1.4.18/lib/basename-lgpl.c:39:3
for (p = base; *p; p++)
    {
      if (ISSLASH (*p))
        saw_slash = true;
      else if (saw_slash)
        {
          base = p;
          saw_slash = false;
        }
    }



//m4-1.4.18/lib/basename-lgpl.c:63:3

 for (len = strlen (name);  1 < len && ISSLASH (name[len - 1]);  len--)
    continue;


//make-4.2/ar.c:232:3
 for (p = pattern; *p != '\0'; ++p)
    switch (*p)
      {   
      case '?':
      case '*':
        return 1;

      case '\\':
        if (quote)
          ++p;
        break;

      case '[':
        opened = 1;
        break;

      case ']':
        if (opened)
          return 1;
        break;
      }   


//make-4.2/file.c:902:3
 p += strlen (p) - 1;
  while (*p == '0')
    p--;


//make-4.2/function.c:2456:3

  for (nargs=1, end=beg; *end != '\0'; ++end)
    if (*end == ',')
      ++nargs;
    else if (*end == openparen)
      ++count;
    else if (*end == closeparen && --count < 0)
      break;


//make-4.2/function.c:330:3
 for (; ptr < end; ++ptr)
    if (*ptr == startparen)
      ++count;

    else if (*ptr == endparen)
      {
        --count;
        if (count < 0)
          return NULL;
      }

    else if (*ptr == ',' && !count)
      return (char *)ptr;


//make-4.2/job.c:2615:5
   for (cap = ifs; *cap != '\0'; ++cap)
      if (*cap != ' ' && *cap != '\t' && *cap != '\n')
        goto slow;


//make-4.2/misc.c:61:3
 in = strchr (line, '\n');
  if (in == 0)
    return;

  out = in;
  while (out > line && out[-1] == '\\')
    --out;


//make-4.2/misc.c:309:3
while (s < limit)
    if (*s++ == c)
      return (char *)(s - 1);


//make-4.2/read.c:1780:11
for (line = s2; *line != '\0'; ++line)
  {
    if (*line == '(')
      ++count;
    else if (*line == ')')
      {
        if (count <= 0)
          break;
        else
          --count;
      }
  }




//make-4.2/read.c:1797:11
while (*line != '\0' && *line != termin)
            ++line;


//make-4.2/read.c:1734:11
for (; *line != '\0'; ++line)
      if (*line == '(')
        ++count;
      else if (*line == ')')
        --count;
      else if (*line == ',' && count <= 0)
        break;


//make 4.2/variable.c:298:7
for (++name; *name != '\0'; ++name)
     if (*name != '_' && (*name < 'a' || *name > 'z')
         && (*name < 'A' || *name > 'Z') && !ISDIGIT(*name))
       break;


//make-4.2/variable.c:1681:9
for (p = v->value; *p != '\0'; ++p)
     {
       if (*p == '$')
         putchar ('$');
       putchar (*p);
     }



//make-4.2/
//make-4.2/



