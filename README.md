# 42minishell
This project is about developing a simplified version of the bash shell.

## Sections
Minishell project is divided into 4 distinct parts:
- Lexer: Takes the entered line as input and reads through the line word by word using white space as delimiters.
- Parser: Groups the different nodes together based on the tokens (i.e. `|`, `<`, etc.). Each group becomes a command.
- Expander: Takes variables, identified by `$`, and replaces them with their value from the environment variables.
- Executor: Is the one in charge of executing the final command.

## Sources
- [Getting Started](https://harm-smits.github.io/42docs/projects/minishell)
