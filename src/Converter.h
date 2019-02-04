/**
 * @file Converter.h
 * Implementation for the Converter class.
 *
 * @author Ivan Milovanov <iam@milovanov.org>
 * @copyright 2019 Ivan Milovanov
 * @license MIT https://github.com/imilovanov/srt-smi/master/LICENSE.txt
 */

#ifndef CONVERTER_H_
#define CONVERTER_H_

#include <string>

class Converter {
 public:
  Converter(int timeOffsetMs = 0, const std::string& outputDir = "",
            bool quiet = false, bool verbose = false)
      /**
       * Converts all files in a directory, optionally converting files in
       * subdirectories.
       *
       * @param dirpath The path to the directory in which to search for .srt
       * files to convert. Can be a full or relative path.
       * @param recursive Set this to TRUE to recursively search subdirectories
       * for .srt files to convert. Defaults to FALSE.
       * @returns 1 if an error occurred; else 0.
       */
      int convertDirectory(std::string& dirpath, bool recursive = false);
  /**
   * Converts a single .srt file to a .smi file.
   *
   * @param filepath The path to the file to convert. Can be a full or relative
   * path.
   * @returns 1 if an error occurred; else 0.
   */
  int convertFile(std::string filepath);

 private:
  int timeStringToMs(const std::wstring& time);  // Converts a SubRip time
                                                 // string to milliseconds
  std::wstring msToSmiTimeString(
      int ms);  // Converts milliseconds to a SAMI-formatted time string
  void print(std::string info,
             bool eol = true);  // Prints information to the console

  int _timeOffsetMs;       // The timing offset in milliseconds
  std::string _outputDir;  // The directory in which the converted .smi files
                           // will be saved
  bool _quiet;             // If true, prevents printing to the console
  bool _verbose;  // If true, extra information will be printed to the console
};

#endif
