
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



//wget-1.9/src/convert.c:538:3
 for (; beg < end; beg++)
    {
      switch (*beg)
  {
  case '&': 
    saw_amp = 1;
    break;
  case '#':
    if (!saw_amp)
      {
        *bp = beg;
        *ep = end;
        return 1;
      }
    /* fallthrough */
  default:
    saw_amp = 0;
  } 
    }

//wget-1.9/src/ftp-basic.c:208:9
for (cp = respline + strlen (skey_head[i]);
     '0' <= *cp && *cp <= '9';
     cp++)
  {
    skey_sequence = skey_sequence * 10 + *cp - '0';
  }



//wget-1.9/src/hash.c:553:5        
   for (p += 1; *p != '\0'; p++)
      h = (h << 5) - h + *p;

//wget-1.9/src/headers.c:203:3
 while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n')
    ++p;

//wget-1.9/src/html-parse.c:475:3
while (state != AC_S_DONE && state != AC_S_BACKOUT)
    {
      if (p == end)
  state = AC_S_BACKOUT;
      switch (state)
  {
  case AC_S_DONE:
  case AC_S_BACKOUT:
    break;
  case AC_S_BANG:
    if (ch == '!')
      {
        ch = *p++;
        state = AC_S_DEFA

...

//wget-1.9/src/http.c:2327:7
for (ep = cp; *ep && *ep != '\"'; ep++);

//wget-1.9/src/init.c:758:7
  for (++val; ISSEP (*val); val++)
  ;


//wget-1.9/src/url.c:532:3
 for (p = url; *p && *p != ':' && *p != '/'; p++)
    ;

//wget-1.9/src/url.c:1255:3
 p = path + strlen (path);
  for (; *p != '/' && p != path; p--)
    ;

//wget-1.9/src/url.c:1617:3
 for (; e > b; e--)
    if (*e == c)
      return e;



//wget-1.9/src/utils.c:352:3
 for (p = string; *p; p++)
    if (*p == chr)
      ++count;

//wget-1.9/src/utils.c:712:3

int l = strlen (s);
while (l && s[l] != '/')
    --l;

//wget-1.9/src/utils.c:882:3
for (; *s; s++)
    if (*s == '*' || *s == '?' || *s == '[' || *s == ']')
      return 1;

//wget-1.9/src/utils.c:1752:3
 for (i = 0; *s; s++, i++)
    {
      if (*s == '&')
  i += 4;     /* `amp;' */
      else if (*s == '<' || *s == '>')
  i += 3;     /* `lt;' and `gt;' */
      else if (*s == '\"')
  i += 5;     /* `quot;' */
      else if (*s == ' ')
  i += 4;     /* #32; */
    }

//libosip2-4.1.0/src/osipparser2/osip_message_parse.c:331:3
while (('\r' != *soh) && ('\n' != *soh)) {
    if (*soh)
      soh++;
    else {
      OSIP_TRACE (osip_trace (__FILE__, __LINE__, OSIP_ERROR, NULL, "Final CRLF is missing\n"));
      return OSIP_SYNTAXERROR;
    }    
  }

//libosip2-4.1.0/src/osipparser2/osip_message_parse.c:217:5
while ((*hp != '\r') && (*hp != '\n')) {
      if (*hp)
        hp++;
      else {
        OSIP_TRACE (osip_trace (__FILE__, __LINE__, OSIP_ERROR, NULL, "No crlf found\n"));
        return OSIP_SYNTAXERROR;
      }
    }

//libosip2-4.1.0/src/osipparser2/osip_message_parse.c:124:5
    while ((*hp != '\r') && (*hp != '\n')) {
      if (*hp) {
        if ((*hp >= '0') && (*hp <= '9'))
          hp++;
        else if (*hp == '.')
          hp++;
        else {
          OSIP_TRACE (osip_trace (__FILE__, __LINE__, OSIP_ERROR, NULL, "incorrect sip version string\n"));
          osip_free (dest->sip_method);
          dest->sip_method = NULL;
          osip_uri_free (dest->req_uri);
          dest->req_uri = NULL;
          return OSIP_SYNTAXERROR;
        }
      }
      else {
        OSIP_TRACE (osip_trace (__FILE__, __LINE__, OSIP_ERROR, NULL, "No crlf found\n"));
        osip_free (dest->sip_method);
        dest->sip_method = NULL;
        osip_uri_free (dest->req_uri);
        dest->req_uri = NULL;
        return OSIP_SYNTAXERROR;
      }
    }

//libosip2-4.1.0/src/osipparser2/osip_port.c:567:3
 while ((' ' == *pend) || ('\r' == *pend) || ('\n' == *pend) || ('\t' == *pend)) {
    pend--;
    if (pend < pbeg) {
      *word = '\0';
      return OSIP_SUCCESS;
    }
  }

//libosip2-4.1.0/src/osipparser2/osip_port.c:563:3
while ((' ' == *pbeg) || ('\r' == *pbeg) || ('\n' == *pbeg) || ('\t' == *pbeg))
    pbeg++

//libosip2-4.1.0/src/osipparser2/osip_port.c:605:3
while ((*sep != end_separator) && (*sep != '\0') && (*sep != '\r')
         && (*sep != '\n'))
    sep++;

//libosip2-4.1.0/src/osipparser2/osip_port.c:1409:3
while ((c = *str++))
    hash = ((hash << 5) + hash) + c;

//libosip2-4.1.0/src/osipparser2/osip_port.c:1476:3
 while ((' ' == *pend) || ('\r' == *pend) || ('\n' == *pend) || ('\t' == *pend)) {
    pend--;
    if (pend < pbeg) {
      *dst = '\0';
      return dst;
    }
  }

//libosip2-4.1.0/src/osipparser2/osip_port.c:1470:3
  while ((' ' == *pbeg) || ('\r' == *pbeg) || ('\n' == *pbeg) || ('\t' == *pbeg))
    pbeg++;

//libosip2-4.1.0/src/osipparser2/osip_from.c:545:5
 for (; *tmp == '\t' || *tmp == ' '; tmp++) {
    }


//libosip2-4.1.0/src/osipparser2/osip_uri.c:241:5
while (host < port && *host != '[')
      host++;

//libosip2-4.1.0/src/osipparser2/osip_uri.c:237:3
while (tmp > host && *tmp != ']')
    tmp--;

//libosip2-4.1.0/src/osipparser2/osip_uri.c:219:3 
 while (port > host && *port != ']' && *port != ':')
    port--;

//libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:120:9
for (; *tmp == ' ' || *tmp == '\t'; tmp++) {
        }

//libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:109:7
for (; *tmp == ' ' || *tmp == '\t'; tmp++) {
      }

//libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:111:7
for (; *tmp == '\n' || *tmp == '\r'; tmp++) {
} 

//libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:144:7
for (; *tmp == ' ' || *tmp == '\t'; tmp++) {
      }

//libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:135:5 
for (; *tmp == '\n' || *tmp == '\r'; tmp++) {
    }  


//libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:133:5
for (; *tmp == ' ' || *tmp == '\t'; tmp++) {
}

//libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:89:5
 while (' ' == *(hack - 1))  /* get rid of extra spaces */
      hack--;

//libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:72:3
 while ((' ' == *str) || ('\t' == *str) || (',' == *str))
    if (*str)
      str++;
    else
      return OSIP_SYNTAXERROR; 
//libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:207:7
for (; *tmp == ' ' || *tmp == '\t'; tmp++) {
 }
//libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:198:5
for (; *tmp == '\n' || *tmp == '\r'; tmp++) {
    }  
//libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:196:5
for (; *tmp == ' ' || *tmp == '\t'; tmp++) {
}

//libosip2-4.1.0/src/src/osipparser2/osip_www_authenticate.c:174:3
while ((' ' == *str) || ('\t' == *str) || (',' == *str))
    if (*str)
      str++;
    else
      return OSIP_SYNTAXERROR;  /* bad header format */

//patch-2.7/src/inp.c:479:6
for (q = p;  *q++ != '\n';  )
      /* do nothing */ ;

//patch-2.7/src/pch.c:2342:3
while (*p == ' ' || *p == '\t')
        p++;
//patch-2.7/src/pch.c:2312:4
while (ISDIGIT (*++p))
     /* do nothing */ ;

//patch-2.7/src/pch.c:2306:7
while (ISDIGIT (*++p))
  /* do nothing */ ;

//patch-2.7/src/pch.c:387:3
for (s = str; (*s >= '0' && *s <= '9') || (*s >= 'a' && *s <= 'f'); s++)
    /* do nothing */ ;

//patch-2.7/src/pch.c:369:3
for (s = sha1; *s; s++)
    if (*s != '0')
      break;

//patch-2.7/src/pch.c:331:4
for (s = str, mode = 0; s < str + 6; s++)
{
       if (*s >= '0' && *s <= '7')
  mode = (mode << 3) + (*s - '0');
       else
  {
   mode = 0;
   break;
  }
}

//patch-2.7/src/pch.c:1228:6
 while (*s != '\n')
    s++;

//patch-2.7/src/pch.c:1223:2
  while (*s == '*')
      s++;
//patch-2.7/src/pch.c:1631:6
  while (*s != '\n')
    s++;

//patch-2.7/src/pch.c:1140:3
 for (s = s0;  ISDIGIT (*s);  s++)
    {
      lin new_n = 10 * n + (*s - '0');
      overflow |= new_n / 10 != n;
      n = new_n;
    }

//patch-2.7/src/util.c:347:4
for (o = t + tlen, olen = 0;
     o > t && ! ISSLASH (*(o - 1));
     o--)
  /* do nothing */ ;

//patch-2.7/src/util.c:168:3
for (; *s; s++)
    if (ISSLASH(*s))
      return true;

//patch-2.7/src/util.c:1230:3
for (f = filename + FILE_SYSTEM_PREFIX_LEN (filename);  ISSLASH (*f);  f++)
    /* do nothing */ ;

//patch-2.7/lib/dirname-lgpl.c:48:3
 /* Strip the basename and any redundant slashes before it.  */
  for (length = last_component (file) - file;
       prefix_length < length; length--)
    if (! ISSLASH (file[length - 1]))
      break;

//patch-2.7/lib/basename-lgpl.c:39:3
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

//patch-2.7/lib/basename-lgpl.c:36:3
  while (ISSLASH (*base))
    base++;

//patch-2.7/lib/hash.c:433:3
  for (; (ch = *string); string++)
    value = (value * 31 + ch) % n_buckets;

//patch-2.7/lib/parse-datetime.y:1283:3
  while ((*yyd++ = *yys++) != '\0')
    continue;

//grep-3.1/src/grep.c:836:3
  for (char const *p = buf; p < buf + size; p++) 
    if (*p) 
      return false;

//grep-3.1/src/searchutils.c:99:9
 for (int i = 1; i <= 3; i++)
          if ((cur[-i] & 0xc0) != 0x80)
            {
              mbstate_t mbs = { 0 };
              size_t clen = mb_clen (cur - i, end - (cur - i), &mbs);
              if (i < clen && clen < (size_t) -2)
                {
                  p0 = cur - i;
                  p = p0 + clen;
                }
              break;
            }

//grep-3.1/lib/exclude.c:552:8
 while (len > 0 && ISSLASH (pattern[len-1]))
    --len;

//grep-3.1/lib/basename-lgpl.c:39:3
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

//grep-3.1/lib/basename-lgpl.c:36:3
  while (ISSLASH (*base))
    base++;

//grep-3.1/lib/hash.c:433:3
  for (; (ch = *string); string++)
    value = (value * 31 + ch) % n_buckets;


//grep-3.1/lib/memchr2.c:162:3
  for (; n > 0; --n, ++char_ptr)
    {
      if (*char_ptr == c1 || *char_ptr == c2)
        return (void *) char_ptr;
    }

//grep-3.1/lib/memchr2.c:62:3
 for (void_ptr = s;
       n > 0 && (uintptr_t) void_ptr % sizeof (longword) != 0;
       --n)
    {
      char_ptr = void_ptr;
      if (*char_ptr == c1 || *char_ptr == c2)
        return (void *) void_ptr;
      void_ptr = char_ptr + 1;
    }

//gawk-4.2.0/builtin.c:3635:3
for (str += 2, len -= 2; len > 0; len--, str++) {
      switch (*str) {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        val = *str - '0';
        break;
      case 'a':
      case 'b':
      case 'c':
      case 'd':
      case 'e':
      case 'f':
        val = *str - 'a' + 10;
        break;
      case 'A':
      case 'B':
      case 'C':
      case 'D':
      case 'E':
      case 'F':
        val = *str - 'A' + 10;
        break;
      default:
        if (endptr)
          *endptr = str;
        goto done;
      }
      retval = (retval * 16) + val;
    }
//gawk-4.2.0/command.y:1524:3
   for (i++, q = p + 1; i < len; i++, q++)
      if (*q == ' ' || *q == '\t')
        break;

//gawk-4.2.0/command.y:1518:2
for (i = 0; i < len; i++, p++)
    if (*p != ' ' && *p != '\t')
      break;

//gawk-4.2.0/ext.c:91:2
 for (sp++; (c = *sp++) != '\0';) {
    if (! is_identchar(c))
      return false;

//gawk-4.2.0/field.c:448:3
 while (scan < end && (*scan == ' ' || *scan == '\t' || *scan == '\n'))
      scan++;

//gawk-4.2.0/int_array.c:104:2
 while (++s < end) {
    if (*s < '0' || *s > '9')
      return false;

//gawk-4.2.0/io.c:4100:2
  while (*cp != '/' && cp < cpend)
    cp++;

//gawk-4.2.0/io.c:4082:2

  while (*cp != '/') {
    if (++cp >= cpend)
      return false;

//gawk-4.2.0/io.c:4066:2
  while (*cp != '/') {
    if (++cp >= cpend)
      return false;

//gawk-4.2.0/io.c:3461:2 
  while (*bp != rs)
    bp++;

//gawk-4.2.0/main.c:1133:3
for (cp2 = arg+1; *cp2; cp2++)
  if (! is_identchar((unsigned char) *cp2)) {
    badvar = true;
    break;
  }

//gawk-4.2.0/mpfr.c:236:2
  for (; *s != '\0'; s++) {
    if (*s == dec_point || *s == 'e' || *s == 'E')
      return true;

//gawk-4.2.0/mpfr.c:162:2
  while (len > 0) {
    switch (*s) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
      break;
    case '8':
    case '9':
      if (base == 8)
        goto done;
      break;
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
      if (base == 16)
        break;
    default:
      goto done;
    }
    s++; len--;
  }

//gawk-4.2.0/str_array.c:736:2
while (len--) {
    hashVal += *str++;
    hashVal += (hashVal << 10);
    hashVal ^= (hashVal >> 6);
  }

//gawk-4.2.0/support/getopt.c:952:2
for (d->__nextchar = nameend = d->optarg; *nameend && *nameend != '=';
       nameend++)
//gawk-4.2.0/support/getopt.c:549:7
for (nameend = d->__nextchar; *nameend && *nameend != '='; nameend++)
  /* Do nothing.  */ ;

//gawk-4.2.0/support/regex_internal.c:738:7
for (; p >= end; --p)
  if ((*p & 0xc0) != 0x80)
      {
        mbstate_t cur_state;
        wchar_t wc2;
        int mlen = raw + pstr->len - p;
        unsigned char buf[6];
        size_t mbclen;

        const unsigned char *pp = p;
        if (BE (pstr->trans != NULL, 0))
          {
            int i = mlen < 6 ? mlen : 6;
            while (--i >= 0) 
        buf[i] = pstr->trans[p[i]];
            pp = buf;
          }
        /* XXX Don't use mbrtowc, we know which conversion
           to use (UTF-8 -> UCS4).  */
        memset (&cur_state, 0, sizeof (cur_state));
        mbclen = __mbrtowc (&wc2, (const char *) pp, mlen,
                &cur_state);
        if (raw + offset - p <= mbclen
            && mbclen < (size_t) -2)
          {
            memset (&pstr->cur_state, '\0',
              sizeof (mbstate_t));
            pstr->valid_len = mbclen - (raw + offset - p);
            wc = wc2;
          }
        break;
	}
}

//sed-4.4/sed/compile.c:306:3
  for (p=buf+1; p < bufend && max <= 255; ++p, max *= base)
    {    
      int d = -1;
      switch (*p) 
        {
        case '0': d = 0x0; break;
        case '1': d = 0x1; break;
        case '2': d = 0x2; break;
        case '3': d = 0x3; break;
        case '4': d = 0x4; break;
        case '5': d = 0x5; break;
        case '6': d = 0x6; break;
        case '7': d = 0x7; break;
        case '8': d = 0x8; break;
        case '9': d = 0x9; break;
        case 'A': case 'a': d = 0xa; break;
        case 'B': case 'b': d = 0xb; break;
        case 'C': case 'c': d = 0xc; break;
        case 'D': case 'd': d = 0xd; break;
        case 'E': case 'e': d = 0xe; break;
        case 'F': case 'f': d = 0xf; break;
        }
      if (d < 0 || base <= d)
        break;
      n = n * base + d; 
    } 


//tar-1.29/src/create.c:991:3
 for (i = sizeof *header; i-- != 0; ) 
    /* We can't use unsigned char here because of old compilers, e.g. V7.  */
    sum += 0xFF & *p++;

//tar-1.29/src/create.c:587:3
  for (i = length - 1; i > 0; i--)
    if (ISSLASH (name[i]))
      break;

//tar-1.29/src/xheader.c:356:3
  while (q > buf && ISSLASH (q[-1]))
    q--;

//tar-1.29/src/xheader.c:684:3
  for (p = len_lim; *p == ' ' || *p == '\t'; p++)
    continue;

//tar-1.29/src/xheader.c:662:3 
  while (*p == ' ' || *p == '\t')
    p++;

//tar-1.29/src/list.c:124:3
  for (p = file_name; *p && (ISSLASH (*p) || *p == '.'); p++)
    ;

//tar-1.29/src/list.c:907:4
  while (where0 != lim && ! lim[-1])
    lim--;

//tar-1.29/src/list.c:789:4
    for (;;)
      {
        value += 7 - digit;
        where++;
        if (where == lim || ! ISODIGIT (*where))
    break;
        digit = *where - '0';
        overflow |= value != (value << LG_8 >> LG_8);
        value <<= LG_8;
      }

//tar-1.29/src/list.c:875:7 
      for (;;)
  {
    value = (value << LG_256) + (unsigned char) *where++;
    if (where == lim)
      break;
    if (((value << LG_256 >> LG_256) | topbits) != value)
      {
        if (type && !silent)
    ERROR ((0, 0,
      _("Archive base-256 value is out of %s range"),
      type));
        return -1;
      }
  }

//tar-1.29/src/list.c:354:3
 for (i = sizeof *header; i-- != 0;)
    {
      unsigned_sum += (unsigned char) *p;
      signed_sum += (signed char) (*p++);
    }

//tar-1.29/src/misc.c:505:4
    while (ISDIGIT (*++p))
      if (digits < LOG10_BILLION)
        digits++, ns = 10 * ns + (*p - '0');
      else
        trailing_nonzero |= *p != '0';

//tar-1.29/src/names.c:1805:3
  while (ISSLASH (*p))
    p++;

//tar-1.29/src/sparse.c:193:3
 while (size--)
    if (*buffer++)
      return false;

//tar-1.29/src/utf8.c:95:3
  for (; *p; p++)
    if (*p & ~0x7f)
      return false;


//tar-1.29/lib/paxnames.c:128:7
for (p = file_name + prefix_len; ISSLASH (*p); p++)
  continue;

//tar-1.29/lib/rtapelib.c:169:3
  for (cursor = command_buffer; *cursor; cursor++)
    if (*cursor != ' ')
      break;

//tar-1.29/lib/rtapelib.c:249:7
for (;;)
  {
    int digit = *status++ - '0';
    if (9 < (unsigned) digit)
      break;
    else
      {
        off_t c10 = 10 * count;
        off_t nc = negative ? c10 - digit : c10 + digit;
        if (c10 / 10 != count || (negative ? c10 < nc : nc < c10))
    return -1;
        count = nc;
      }
  }

//tar-1.29/lib/rtapelib.c:243:7
for (;  *status == ' ' || *status == '\t';  status++)
  continue;

//tar-1.29/lib/wordsplit.c:1185:3
  for (p = quote_transtab; *p; p += 2)
    {
      if (*p == c)
  return p[1];
    }

//tar-1.29/lib/wordsplit.c:1198:3
  for (p = quote_transtab + sizeof (quote_transtab) - 2;
       p > quote_transtab; p -= 2)
    {
      if (*p == c)
  return p[-1];
    }

//tar-1.29/lib/wordsplit.c:1123:8
for (j = i + 1; j < len && command[j] != '\n'; j++)
    ;
//tar-1.29/gnu/argp-help.c:343:3
  while (beg < end)
    if (*beg == ch)
      return 1;
    else
      beg++;

//tar-1.29/gnu/dirname-lgpl.c:48:3
  for (length = last_component (file) - file;
       prefix_length < length; length--)
    if (! ISSLASH (file[length - 1]))
      break;

//tar-1.29/gnu/basename-lgpl.c:39:3
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

//tar-1.29/gnu/basename-lgpl.c:36:3
  while (ISSLASH (*base))
    base++;

//tar-1.29/gnu/basename-lgpl.c:63:3
for (len = strlen (name);  1 < len && ISSLASH (name[len - 1]);  len--)
    continue;

//tar-1.29/gnu/exclude.c:552:8
while (len > 0 && ISSLASH (pattern[len-1]))
    --len;

//tar-1.29/gnu/hash.c:433:3
for (; (ch = *string); string++)
    value = (value * 31 + ch) % n_buckets;

//tar-1.29/gnu/modechange.c:169:5
for (p = mode_string; *p; p++)
      needed += (*p == '=' || *p == '+' || *p == '-');

//tar-1.29/gnu/arse-datetime.y:1319:13
while (c = *p, c_isspace (c))
              p++;

//tar-1.29/gnu/parse-datetime.y:1283:3
while (c = *p, c_isspace (c))
    p++;

//tar-1.29/gnu/getopt.c:927:9 
for (d->__nextchar = nameend = d->optarg; *nameend && *nameend != '=';
  nameend++)
  /* Do nothing.  */ ;

//tar-1.29/gnu/getopt.c:507:7
for (nameend = d->__nextchar; *nameend && *nameend != '='; nameend++)
        /* Do nothing.  */ ;
      namelen = nameend - d->__nextchar;


