# Macros

Macro are made to add some intels about the debug added like the file that call debug and the line number.

Macro are different in two ways :&#x20;

* in KapEngine namespace
* out of KapEngine namespace

This difference is made because of your code if it's include in namespace KapEngine or not.

## In Namespace KapEngine

* DEBUG\_LOG
* DEBUG\_WARNING
* DEBUG\_ERROR

## Out of Namespace KapEngine

* KAP\_DEBUG\_LOG
* KAP\_DEBUG\_WARNING
* KAP\_DEBUG\_ERROR



All of these macros used Debug::log, Debug::warning or Debug::error. describe in [class Debug](class-debug.md)
