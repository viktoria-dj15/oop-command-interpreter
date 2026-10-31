# English translation of the project assignment

[Read the English PDF](Project-Assignment-2025-v1.0-English.pdf)

Translated from the supplied Serbian document **Projektni zadatak 2025 - v1.0.pdf**, issued by the School of Electrical Engineering in Belgrade for Object-Oriented Programming (1), academic year 2025/2026. The assignment applies from the February 2026 examination period. This is an unofficial English translation; the Serbian original remains authoritative.

The translation retains all 13 pages, the original section order and page divisions, command syntax and examples, numbered requirements, footnotes, and revision table. It recreates the A4 layout with Times New Roman body text, Arial headings, Courier New examples, and colored emphasis anchored to the corresponding English passages. Line wrapping and highlight boundaries necessarily differ. Non-textual blue handwritten ticks, circles, and brackets have not been reproduced.

## Source inconsistencies and editorial choices

- The source contents page has several outdated page references. The English contents page points to the actual pages: `date`, `touch`, `truncate`, `rm`, and `wc` on page 8; `tr`, `head`, and `batch` on page 9; Error Handling on page 10.
- The pipeline example on page 9 redirects to `time.txt`, while its explanation on page 10 names `text.txt`. Both names have been retained as printed in the source.
- In the assessment procedure on page 11, a paragraph introducing hidden tests then refers to failure of a **public** test. The translation retains that wording rather than silently substituting “hidden.”
- Footnote 3 on page 5 states that typed input characters are not displayed. This statement has been preserved; terminal echo in a real environment can be controlled independently of the command's output.
- The `tr` description in the source has an incomplete grammatical construction. It is rendered as finding and replacing occurrences, consistent with the `what`/`with` syntax, the removal behavior when `with` is omitted, and the pipeline example.
- The typographic dash before `what` has been normalized to the ASCII hyphen used by the command examples. Command names, options, filenames, and literal example text have not been translated.
- The general Error Handling section says errors are written to the output stream, while an earlier section defines a separate error output stream. Those statements are preserved as written.

This translation documents the assignment requirements. It does not assert that the repository implementation satisfies every requirement.
