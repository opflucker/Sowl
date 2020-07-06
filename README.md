# Sowl

## Introduction

Years ago, when development Microsoft Windows native graphical applications was more common, programmers have to work directly with 
the Windows C APIs. Those APIs are themselves written mostly in C, so C/C++ language was commonly used. But given the C nature of those APIs,
and their internal designs, programmers were strongly limited when coding object oriented programs. The alternative was to use a more 
object-oriented library that acts as a layer over Windows APIs. Common libraries were MFC, OWL and Qt. 

These libraries suffer from some problems:
- They introduce a dark box layer over the original APIs. This quickly becomes painful when program grows and bugs fall behind that dark box.
- They introduce new concepts (like message maps) that makes hard, again, resolve bugs.
- They abuse of macros (like message maps) that makes hard, again, resolve bugs.
- Even promoted as "lightweights", these libraries are heavy and complex.
- In Qt, its multiplatform nature play against it with a more complex class hierarchy and a problematic runtime linking mechanism.

Even now, with memory managed alternatives (.NET and MPF), working directly with Windows APIs is relevant in many contexts. This project 
is an experimental library that targets these objetives:
- Be simple. Avoid deep and complex class hierarchies. Avoid long methods. Avoid complex resource allocation/release strategies. Avoid multiplatform.
- Be small. Avoid try to cover all Windows APIs functionality, only the more common cases.
- Use original Windows APIs concepts. Avoid hide them, avoid introduce new ones.
- Ease programmers work directly with Windows APIs when they want.
- Avoid macros at all.
