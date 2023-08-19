# Wpq

_Wpq_ is the WikiPedia Query tool.  It allows you to look up a term
and disambiguate if necessary, using Wikipedia's API to open pages
directly in your `$browser` or show you the PDF file in **page(1)**.

# Usage

Let's say we've been reading PC stuff and just learned about the A20
line.  We go ahead and ask wpq for more info about it:

	% wpq a20

However, _a20_ by itself is too ambiguous, so we'll get a list of
possible subjects for us to choose manually:

```
% wpq a20
1) A20
2) A20 line
3) A20 road (England)
4) A202 road
5) A20 autoroute
6) A201 road
7) A206 road
8) A20 heavy tank
9) A200 road
10) A20 cells
[1-10]: 
```

We are only interested in the A20 line, so we go ahead and type the
index number corresponding to the entry:

```
% wpq a20
1) A20
2) A20 line
…
[1-10]: 2
```

And by default this will open up the article in **page(1)** after
fetching it with **hget(1)**.  If instead you want to see it in your
`$browser`, pass the `-h` flag to _wpq_, and it will plumb the URL.
