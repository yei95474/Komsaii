# Komsaii Repository Map

This repo is organized as `year -> subject -> category`.

## Top-level layout

- `first-year/` - first-year work, grouped by subject
- `second-year/` - second-year work, grouped by subject
- `archive/legacy/` - old content kept for history only
- `reference/` - reusable config, editor, and support files
- `jsons/` - active editor/task configuration

## Current subjects

- `first-year/foundational-programming/`
- `second-year/data-structures/`

## Inside each subject

- `learning-materials/` - lecture notes, PDFs, diagrams, mentorship packs, and reference reading
- `practice-problems/` - solved and unsolved problem sets
- `laboratories/` - lab work, sequential exercises, and coursework submissions
- `demos/` - playgrounds, experiments, and short showcase code

## Naming rules

- Use lowercase `kebab-case` for new folder names.
- Prefer `year/subject/category/topic/item-name` paths.
- Keep each folder name semantically specific.
- Put finished exercises under `practice-problems/`.
- Put classwork and required submissions under `laboratories/`.
- Put explanatory material under `learning-materials/`.
- Put experimental or scratch code under `demos/`.
- Put dead or outdated material under `archive/legacy/`.
- Do not keep compiler outputs in the repo tree. Discard generated `.exe`, `.o`, `.obj`, `.ilk`, `.pdb`, `.idb`, and similar build artifacts.
