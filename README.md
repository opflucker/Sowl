# Simple Object Window Library (Sowl)

Sowl is a C++ object-oriented and light library for Microsoft Windows native graphical applications.

## Objetives

Design objetives:
- Be simple: Avoid complex implementation. Avoid complex class hierarchies. Avoid complex resource allocation/release strategies. Avoid multiplatform.
- Be small: Avoid try to cover all Windows APIs functionality, only the more common cases.
- Keep original concepts: Use original Windows APIs concepts. Avoid hide them, avoid introduce new ones.
- Easy resources management: Easy allocate/release Windows resources in the right way, no matters encapsulator objects are created on heap or stack.
- Easy escape: Ease programmers work directly with Windows APIs when they want.
- Use patterns: Use well-known software design patters.
- Avoid macros at all.

## Motivation

Years ago, when development Microsoft Windows native graphical applications was more common, programmers have to work directly with 
the Windows C APIs. Those APIs are themselves written mostly in C, so C/C++ language was commonly used. But given the C nature of those APIs,
and their internal designs, programmers were strongly limited when coding object oriented programs. The alternative was to use a more 
object-oriented library that acts as a layer over Windows APIs. Popular libraries were (and still are) MFC, OWL, wxWidgets and Qt. 

These libraries suffer from some problems that makes harder resolve bugs when working with them:
- They introduce a dark box layer over the original APIs. This quickly becomes painful when program grows.
- They introduce new concepts that are internally mapped to original ones.
- They abuse of macros.
- Even promoted as "lightweights", these libraries are heavy and complex.

Multiplatform alternatives, like wxWidgets and Qt, add more complexity and additional problems, like the problematic runtime linking mechanism of Qt.

Even now, with memory managed alternatives (.NET and MPF), working directly with Windows APIs is relevant in many contexts. This library aims to these contexts.

# Hello World

```CPP
#include <Sowl/Sowl.h>

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE, _In_ PWSTR, _In_ int nCmdShow)
{
    sowl::CustomWindow window(hInstance, L"MyWindowClass");
    window.Show(nCmdShow);
    return sowl::MessageLoop().Run();
}
```

# Documentation

See generated documentation [here](https://opflucker.github.io/Sowl/doc).
