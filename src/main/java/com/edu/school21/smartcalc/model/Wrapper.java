package com.edu.school21.smartcalc.model;

import com.sun.jna.Native;
import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;


public class Wrapper implements WrapperCore {

    private final WrapperCore reversePolishNotation;

    public Wrapper(final String libraryName) {
        try {
            File libraryFile = extractLibrary(libraryName);
            reversePolishNotation = Native.loadLibrary(libraryFile.getAbsolutePath(), WrapperCore.class);
        } catch (IOException e) {
            throw new RuntimeException("Failed to extract library from resources", e);
        }
    }

    @Override
    public double ComputePolishNotation(String str, double x) {
        return reversePolishNotation.ComputePolishNotation(str, x);
    }

    private File extractLibrary(String libraryName) throws IOException {
        Path tempDir = Files.createTempDirectory("libs");
        Path tempFile = tempDir.resolve(Paths.get(libraryName).getFileName());
        try (java.io.InputStream inputStream = getClass().getResourceAsStream("/" + libraryName)) {
            assert inputStream != null;
            Files.copy(inputStream, tempFile);
        }
        tempFile.toFile().deleteOnExit();
        return tempFile.toFile();
    }
}