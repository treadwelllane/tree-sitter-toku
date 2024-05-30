package tree_sitter_toku_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-toku"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_toku.Language())
	if language == nil {
		t.Errorf("Error loading Toku grammar")
	}
}
