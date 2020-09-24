let mapleader = " "
fun! ExerciseName(str) 
	let m = matchstr(a:str, '\zs.*\ze_')
	echom m
	if (m != "") 
	   return m
  	endif
	return matchstr(a:str, '\zs.*\ze\.')
endfunc

fun! CompileExercise()
	let name = ExerciseName(expand('%:t'))
	execute "! gcc" . " " . name . "_test.c " .  expand('%:t') . " && ./a.out" 
endfunc

" nnoremap <leader>e :! gcc :ExerciseName(%:t)_solution.c %:t && ./a.out 
nnoremap <leader>e :call CompileExercise()
nnoremap <leader>r :execute "! gcc " . expand("%:t") . " && ./a.out"

