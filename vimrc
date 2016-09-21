" All system-wide defaults are set in $VIMRUNTIME/debian.vim and sourced by
" the call to :runtime you can find below.  If you wish to change any of those
" settings, you should do it in this file (/etc/vim/vimrc), since debian.vim
" will be overwritten everytime an upgrade of the vim packages is performed.
" It is recommended to make changes after sourcing debian.vim since it alters
" the value of the 'compatible' option.

" This line should not be removed as it ensures that various options are
" properly set to work with the Vim-related packages available in Debian.
runtime! debian.vim

" Uncomment the next line to make Vim more Vi-compatible
" NOTE: debian.vim sets 'nocompatible'.  Setting 'compatible' changes numerous
" options, so any other options should be set AFTER setting 'compatible'.
"set compatible

" Vim5 and later versions support syntax highlighting. Uncommenting the next
" line enables syntax highlighting by default.
if has("syntax")
  syntax on
endif

" If using a dark background within the editing area and syntax highlighting
" turn on this option as well
"set background=dark

" Uncomment the following to have Vim jump to the last position when
" reopening a file
"if has("autocmd")
"  au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
"endif

" Uncomment the following to have Vim load indentation rules and plugins
" according to the detected filetype.
"if has("autocmd")
"  filetype plugin indent on
"endif

" The following are commented out as they cause vim to behave a lot
" differently from regular Vi. They are highly recommended though.
"set showcmd		" Show (partial) command in status line.
"set showmatch		" Show matching brackets.
"set ignorecase		" Do case insensitive matching
"set smartcase		" Do smart case matching
"set incsearch		" Incremental search
"set autowrite		" Automatically save before commands like :next and :make
"set hidden		" Hide buffers when they are abandoned
"set mouse=a		" Enable mouse usage (all modes)

" Source a global configuration file if available
if filereadable("/etc/vim/vimrc.local")
  source /etc/vim/vimrc.local
endif

" FOR TRAINING
execute pathogen#infect()
filetype plugin indent on
map <F6> ggO/*<CR><TAB>Time:<CR>Prob:<CR>By RogerRo<CR><BACKSPACE><BACKSPACE>/<CR>#include<iostream><CR>#include<cstdio><CR>#include<cstring><CR>#include<cstdlib><CR>#include<set><CR>#include<queue><CR>#include<cmath><CR>#include<vector><CR>#include<algorithm><CR>#include<map><CR>#define ll long long<CR>#define oo 0x7F7F7F7F<CR>#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)<CR>using namespace std;<CR>int read()<CR>{<CR><TAB>int x=0,f=1;<CR>char ch=getchar();<CR>while (!(ch>='0' && ch<='9')) {if (ch=='-') f=-1; ch=getchar();}<CR>while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}<CR>return x*f;<CR>}<CR><CR>int main()<CR>{<CR><CR><TAB>return 0;<CR>}<CR><ESC>

" FOR CONTEST
colo torte
set nu
set ts=4
set sw=4
map <C-A> ggVG"+y
map <F2> :w<CR>
map <F3> :browse e<CR>
map <F4> :browse vsp<CR>
map <F5> :call Run()<CR>
func! Run()
	exec "w"
	exec "!g++ -Wall % -o %<"
	exec "!./%<"
endfunc
